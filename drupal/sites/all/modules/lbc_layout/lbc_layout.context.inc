<?php
/**
 * @file
 * lbc_layout.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function lbc_layout_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'lbc_content';
  $context->description = 'Overall layout for all LBC content pages';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
        '~*admin*' => '~*admin*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-6' => array(
          'module' => 'block',
          'delta' => 6,
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'simpleuplink-simpleuplink' => array(
          'module' => 'simpleuplink',
          'delta' => 'simpleuplink',
          'region' => 'sidebar_first',
          'weight' => '-1',
        ),
        'menu_block-1' => array(
          'module' => 'menu_block',
          'delta' => 1,
          'region' => 'sidebar_first',
          'weight' => '0',
        ),
        'views-banner-banner_block' => array(
          'module' => 'views',
          'delta' => 'banner-banner_block',
          'region' => 'navigation',
          'weight' => '0',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'block-2' => array(
          'module' => 'block',
          'delta' => 2,
          'region' => 'footer',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Overall layout for all LBC content pages');
  $export['lbc_content'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'lbc_permalinks';
  $context->description = 'For all pages that require AddThis buttons excluding civicrm which adds its own share where needed';
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
        'block-9' => array(
          'module' => 'block',
          'delta' => 9,
          'region' => 'content',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('For all pages that require AddThis buttons excluding civicrm which adds its own share where needed');
  $export['lbc_permalinks'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'lbc_retreat_booking';
  $context->description = 'Adds view for solitary retreat booking';
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
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Adds view for solitary retreat booking');
  $export['lbc_retreat_booking'] = $context;

  return $export;
}
