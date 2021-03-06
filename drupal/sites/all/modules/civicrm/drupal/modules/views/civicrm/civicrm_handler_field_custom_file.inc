<?php
/*
 +--------------------------------------------------------------------+
 | CiviCRM version 4.1                                                |
 +--------------------------------------------------------------------+
 | This file is a part of CiviCRM.                                    |
 |                                                                    |
 | CiviCRM is free software; you can copy, modify, and distribute it  |
 | under the terms of the GNU Affero General Public License           |
 | Version 3, 19 November 2007 and the CiviCRM Licensing Exception.   |
 |                                                                    |
 | CiviCRM is distributed in the hope that it will be useful, but     |
 | WITHOUT ANY WARRANTY; without even the implied warranty of         |
 | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.               |
 | See the GNU Affero General Public License for more details.        |
 |                                                                    |
 | You should have received a copy of the GNU Affero General Public   |
 | License and the CiviCRM Licensing Exception along                  |
 | with this program; if not, contact CiviCRM LLC                     |
 | at info[AT]civicrm[DOT]org. If you have questions about the        |
 | GNU Affero General Public License or the licensing of CiviCRM,     |
 | see the CiviCRM license FAQ at http://civicrm.org/licensing        |
 +--------------------------------------------------------------------+
*/
  /*
   / * Unchanged anonymous code contribution. No claim.
   *
   * civicrm_handler_field_custom_file.inc
   * Displays File field uri instead of id.
   *
   */
  /**
   * Field handler to provide acess control for the File field
   *
   * @ingroup civicrm_field_handlers
   */
class civicrm_handler_field_custom_file extends views_handler_field {
    function construct( ) {
        civicrm_initialize( );
        $this->additional_fields['entity_id'] = 'entity_id';
    }
    
    function render( $values ) {
        $value = $values->{$this->field_alias};
        if ( ! is_null( $value ) ) {
            $fileType = CRM_Core_DAO::getFieldValue( 'CRM_Core_DAO_File',
                                                     $value,
                                                     'mime_type' );
            
            if ( $fileType && in_array($fileType,  array( "image/jpeg", "image/pjpeg", "image/gif", "image/x-png", "image/png" ) ) ) {
                $uri = CRM_Core_DAO::getFieldValue( 'CRM_Core_DAO_File',
                                                    $value,
                                                    'uri' );
                $config = CRM_Core_Config::singleton( );
                return str_replace( 'persist/contribute', 'custom', $config->imageUploadURL) . $uri;
            } else {
                $entityField = $this->aliases['entity_id'];
                return  CRM_Utils_System::url( 'civicrm/file',
                                               "reset=1&id={$value}&eid={$values->$entityField}",
                                               true, null, true, true );
            }
        }
        return null;
    }
  }
?>