$(document).ready(function() {
    $('.dropdown-item').click(function() {
      $('#dropdownMenuButton').text($(this).text());
    });
  });
  
  function toggleButton() {
    var button = document.getElementById("toggle-button");
    if (button.classList.contains("button1")) {
      button.innerHTML = "Add to Basket";
      button.classList.remove("button1");
      button.classList.add("button2");
    } else {
      window.location.href = "#";
    }
  }

  function IngredientsButton(){
    var textContainer = document.getElementById("Ingredients-container");
    var button = document.getElementById("toggle-button-ingredients");
    if (textContainer.style.display === "none") {
      textContainer.style.display = "block";
     
      
    } else {
      textContainer.style.display = "none";
      
    }

  }
  