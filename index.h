String MAIN_page = R"=====(
<!DOCTYPE html>
<html>
<body>

    <h3>Current sensor state</h3>
     <button id="btn2" onclick="MainFunctionB(0)">Start</button>
    <button onclick="MainFunctionB(1)">Stop</button>
    
    <div id="adc" style="font-size:22px; margin-top:15px;"></div>
    
<br><br>
    <h3>Sensor data recording</h3>
 <button id="btn" onclick="MainFunction(0)">Start</button>
    <button onclick="MainFunction(1)">Stop</button>

  <br><br>  
<div>
  <table id="dataTable" onclick="selectText('dataTable')">
    <tr><th>Time</th><th>ADC Value</th></tr>
  </table>
</div>


<script>

var n = 0;
    
function MainFunction(cancel) {
var yourcode;
  if (cancel == 0) {
    yourCode = setInterval(function() {
      
      getData();
    }, 20);
    
    function getData() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            var ADCValue = this.responseText;
           
        
        
    var table = document.getElementById("dataTable");
    var row = table.insertRow(1); //Add after headings
    var cell1 = row.insertCell(0);
    var cell2 = row.insertCell(1);
    cell1.innerHTML = (n/50);
    cell2.innerHTML = ADCValue;
      n = n + 1;
        }
  };
  xhttp.open("GET", "/readADC", true);  
  xhttp.send(); 
  };
  }
      
  if (cancel == 1) {
    clearInterval(yourCode);
    //document.getElementById('div').style.color = "black";
  }
}


function selectText(containerid) {
    if (document.selection) { // IE
        var range = document.body.createTextRange();
        range.moveToElementText(document.getElementById(containerid));
        range.select();
    } else if (window.getSelection) {
        var range = document.createRange();
        range.selectNode(document.getElementById(containerid));
        window.getSelection().removeAllRanges();
        window.getSelection().addRange(range);
    }
}

    
function MainFunctionB(cancel) {
var yourcodeB;
  if (cancel == 0) {
    yourCodeB = setInterval(function() {
      
      getData();
    }, 1000);
    
    function getData() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("adc").innerHTML = this.responseText;
           
      
        }
  };
  xhttp.open("GET", "/readADC", true);  
  xhttp.send(); 
  };
  }
      
  if (cancel == 1) {
    clearInterval(yourCodeB);
    //document.getElementById('div').style.color = "black";
  }
}
    
    

</script>


</body>
</html>
)=====";
