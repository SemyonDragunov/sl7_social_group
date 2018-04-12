(function ($, Drupal, window, document, undefined) {
	Drupal.ajax.prototype.commands.socialGroup = function(ajax, response, status) {
		var $social_tabs = $('.sl7-social-group'),
			$div_name = $social_tabs.find('> section > div#' + response.name);

		$social_tabs.find('.active').removeClass('active');
		$social_tabs.find('#' + response.name).addClass('active');

		if (!$div_name.children().length) {
			$div_name.prepend(response.data);
		}
	}
})(jQuery, Drupal, this, this.document);