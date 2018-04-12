<?php

/**
 * @author Semyon Dragunov <sam.dragunov@gmail.com>
 * https://github.com/SemyonDragunov
 */


function template_preprocess_sl7_social_group__block_groups(&$variables) {
  $variables['conf'] = variable_get('sl7_social_group');
  drupal_add_library('system', 'drupal.ajax');
  drupal_add_css(drupal_get_path('module', 'sl7_social_group') . '/css/sl7_social_group.css');
  drupal_add_js(drupal_get_path('module', 'sl7_social_group') . '/js/sl7_social_group.js');
}

function theme_sl7_social_group__block_groups($variables) {
  $conf = $variables['conf'];
  $def_tab = $conf['def_tab'];
  unset($conf['def_tab']);
  $i = count($conf);

  if ($conf) {
    $content =  '<div class="sl7-social-group">';
    $content .=     '<div class="wrapper">';
    if ($i > 1) {
      foreach ($conf as $name => $data) {
        $active = $name == $def_tab ? ' active' : '';
        $content .= !empty($data) ? "<span id='$name' class='sg-col-{$i}{$active}'><a href='/ajax/sl7-social-group/$name' class='use-ajax'></a></span>" : '';
      }
    }
    $content .=     '</div>';
    $content .=     '<section>';

    foreach ($conf as $name => $data) {
      $active = $name == $def_tab ? 'class="active"' : '';
      $output = !empty($active) ? $data : '';
      $content .= !empty($conf['vk']) ? "<div $active id='$name'>$output</div>" : '';
    }

    $content .=     '</section>';
    $content .= '</div>';

    return $content;
  }
}