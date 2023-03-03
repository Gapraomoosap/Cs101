$(document).ready(function() {
    $('.dropdown-item').click(function() {
      $('#dropdownMenuButton').text($(this).text());
    });
  });