<?php
/**
 * A handler to run a field through check_markup, using the default format
 *
 */
class civicrm_handler_field_markup extends views_handler_field {
    function construct() {
        parent::construct();
    }

    function render($values) {
        $value = $values->{$this->field_alias};
        $retval = check_markup($value, filter_fallback_format(), FALSE);
        return ( $retval == 'n/a' ) ? null : $retval;
    }
}
