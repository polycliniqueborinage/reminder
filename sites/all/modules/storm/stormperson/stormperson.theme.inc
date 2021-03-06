<?php

/**
 * @file
 */

function theme_stormperson_view($node, $teaser = FALSE, $page = FALSE) {
  drupal_add_css(drupal_get_path('module', 'storm') . '/storm-node.css');
  
  $node = node_prepare($node, $teaser);
  
  $node->content['links'] = array(
    '#prefix' => '<div class="stormlinks"><dl>',
    '#suffix' => '</dl></div>',
    '#weight' => -25,
  );

  $node->content['group1'] = array(
    '#prefix' => '<div class="stormfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group1') : -20,
  );

  $node->content['group1']['organization'] = array(
    '#prefix' => '<div id="organization">',
    '#suffix' => '</div>',
    '#value' => theme('storm_view_item', t('Organization'), l($node->organization_title, 'node/'. $node->organization_nid)),
    '#weight' => 1,
  );

  $node->content['group2'] = array(
    '#prefix' => '<div class="stormfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group2') : -19,
  );

  $node->content['group2']['fullname'] = array(
    '#prefix' => '<div id="fullname">',
    '#suffix' => '</div>',
    '#value' => theme('storm_view_item', t('Fullname'), $node->fullname),
    '#weight' => 1,
  );
  
  $node->content['group3'] = array(
    '#prefix' => '<div class="stormfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group3') : -18,
  );

  $node->content['group3']['email'] = array(
    '#prefix' => '<div id="email">',
    '#suffix' => '</div>',
    '#value' => theme('storm_view_item', t('Email'), l($node->email, 'mailto:'. $node->email, array('absolute' => TRUE))),
    '#weight' => 1,
  );

  $node->content['group3']['www'] = array(
    '#prefix' => '<div id="www">',
    '#suffix' => '</div>',
    '#value' => theme('storm_view_item', t('WWW'), l($node->www, $node->www, array('absolute' => TRUE))),
    '#weight' => 2,
  );
  
  $node->content['group4'] = array(
    '#prefix' => '<div class="stormfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group4') : -17,
  );

  $node->content['group4']['phone'] = array(
    '#prefix' => '<div id="phone">',
    '#suffix' => '</div>',
    '#value' => theme('storm_view_item', t('Phone'), $node->phone),
    '#weight' => 1,
  );

  $node->content['group4']['im'] = array(
    '#prefix' => '<div id="im">',
    '#suffix' => '</div>',
    '#value' => theme('storm_view_item', t('IM'), $node->im),
    '#weight' => 2,
  );

  $node->content['body_field'] = array(
    '#prefix' => '<div class="stormbody">',
    '#suffix' => '</div>',
    '#value' => theme('storm_view_item', t('Description'), $node->content['body']['#value']),
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'body_field') : -18,
  );
  
  unset($node->content['body']);

  return $node;
}
