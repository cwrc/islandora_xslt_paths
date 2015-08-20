# Islandora XSLT Paths

## Introduction

Islandora XLST Paths permits custom xml form dublin-core transforms and self-transforms 
to be provided in locations outside of the islandora_xml_forms/builder/ directory. If you
add custom xslt files to either the islandora_xml_forms/builder/transforms or 
islandora_xml_forms/builder/self-transforms directory, they will be lost when you 
download a new copy of the islandora_xml_forms module. The purpose of this module is 
to prevent this hazard. 

## Requirements

This module requires the following modules/libraries:

* [Islandora](https://github.com/islandora/islandora)
* [XML Form Builder](https://github.com/Islandora/islandora_xml_forms) (part of the Islandora XML Forms module)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Configuration

First, create your custom locations for dc transform xslt files and/or self-transform xslt files.
Then go to /admin/islandora/xmlform/settings and enter either or both paths.
The xsl files inside those folders will then become available on the form association configuration pages.

## Troubleshooting/Issues

Having problems or solved a problem? Check out the Islandora google groups for a solution.

* [Islandora Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora)
* [Islandora Dev Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora-dev)

## Maintainers/Sponsors
Current maintainers:

* [Pat Dunlavey](https://github.com/patdunlavey)

This project has been sponsored by:

* Williams College.

## Development

If you would like to contribute to this module, please check out our helpful [Documentation for Developers](https://github.com/Islandora/islandora/wiki#wiki-documentation-for-developers) info, as well as our [Developers](http://islandora.ca/developers) section on the Islandora.ca site.

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)