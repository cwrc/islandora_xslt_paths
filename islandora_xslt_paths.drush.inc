<?php

/**
 * @file
 *  Custom CWRC drush scripts.
 **/


/**
 * Implements hook_drush_command().
 **/
function islandora_xslt_paths_drush_command() 
{
  $items = array();

  $items['islandora_xslt_paths_apply_xslt'] = array(
    'description' => 'Apply XSLT to a list of objects with a source and destination datastream',
    'examples' => array(
      'drush -u 1 islandora_xslt_paths_apply_xslt {XSLT_PATH} {DS_SRC} {DS_DEST} {list_of_pids}'
      , 'drush -u 1  islandora_xslt_paths_apply_xslt sites/default/libraries/islandora_cwrc_xslt_library/xslt/mods_to_dc.xsl MODS DC /tmp/z'
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_MAX
  );
 
  return $items;
}



/**
 * Constructs and performs the citation batch operation.
 *
 * @param array $context
 *    The context of the Drupal batch.
 */
function drush_islandora_xslt_paths_apply_xslt(
  $xslt_path
  , $ds_src
  , $ds_dest
  , $list_of_pids_path
  ) 
{

  drush_print("XSLT: " . $xslt_path);
  drush_print("ds src: " . $ds_src);
  drush_print("ds dest: " . $ds_dest);
  drush_print("list: " . $list_of_pids_path);

  //$xslt_lib_path = libraries_get_path('');
  //$xslt_lib_path = drupal_realpath($xslt_lib_path);

  // setup XSLT
  $xsl_doc = new DOMDocument();         
  $xsl_doc->load($xslt_path);             
  $xslt_proc = new XSLTProcessor();     
  $xslt_proc->importStylesheet($xsl_doc);

  // open list of PIDs, one per line
  $handle = fopen($list_of_pids_path, "r");
  if ($handle) 
  {
    while (($pid = fgets($handle)) !== false)
    {
      $pid = trim($pid);

      drush_print("PID: [" . $pid . "]");

      $object = islandora_object_load($pid);

      $ds_src_obj = $object[$ds_src];
      $ds_dest_obj = $object[$ds_dest];

      $tmp_xml = $ds_src_obj->content;

      $tmp_dom = new DOMDocument();
      $tmp_dom->loadXML($tmp_xml);
      $tmp_xml = $xslt_proc->transformToXML($tmp_dom);

      $ds_dest_obj->setContentFromString($tmp_xml);
      $object->ingestDatastream($ds_dest_obj);
    }
    fclose($handle);
  }

}
