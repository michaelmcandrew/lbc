<?php
/**
 * @file
 * lbclayout.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function lbclayout_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'lbc_content';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
        '~*admin*' => '~*admin*',
        '~civicrm' => '~civicrm',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'simpleuplink-simpleuplink' => array(
          'module' => 'simpleuplink',
          'delta' => 'simpleuplink',
          'region' => 'sidebar_first',
          'weight' => '-11',
        ),
        'block-6' => array(
          'module' => 'block',
          'delta' => 6,
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => 1,
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-banner-banner_block' => array(
          'module' => 'views',
          'delta' => 'banner-banner_block',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
        'block-9' => array(
          'module' => 'block',
          'delta' => 9,
          'region' => 'content',
          'weight' => '-7',
        ),
        'block-2' => array(
          'module' => 'block',
          'delta' => 2,
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['lbc_content'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'lbc_retreat_booking';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'retreats/solitary/book' => 'retreats/solitary/book',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'panels_mini-retreat_availability_panel' => array(
          'module' => 'panels_mini',
          'delta' => 'retreat_availability_panel',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['lbc_retreat_booking'] = $context;

  return $export;
}
