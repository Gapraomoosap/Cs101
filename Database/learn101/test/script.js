$(document).ready(function() {
    $('.dropdown-item').click(function() {
      $('#dropdownMenuButton').text($(this).text());
    });
  });
  
  

  // Get the Delivery and Pick Up buttons
  function updateDropdownOptions() {
    // Get the dropdown and its options
    alert("Hello!!");
    // Set new options based on which button was clicked
    if (buttonClicked == 1) {
      alert("123");
      // dropdown.setAttribute("title", "Number");
      // options.add(new Option("1", "1"));
      // options.add(new Option("2", "2"));
      // options.add(new Option("3", "3"));
    } else if (buttonClicked == 2) {
      alert("456");
      // dropdown.setAttribute("title", "Alfa");
      // options.add(new Option("a", "a"));
      // options.add(new Option("b", "b"));
      // options.add(new Option("c", "c"));
    }
    
    // If the dropdown has no options, set the title to a default value
    // if (options.length == 0) {
    //   dropdown.setAttribute("title", "Select an option");
    // }
  }