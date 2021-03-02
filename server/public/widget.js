var achtergrondPlaatje;
var laatsteUpdateTimeStamp;
var button;
var numberOfButtonPresses = 0;

//scores
var scoreRechts = 0;
var scoreLinks = 0;

/**
 * preload
 * deze functie wordt als eerste javascriptfunctie uitgevoerd,
 * dus zelfs nog vóór setup() !
 * Gebruik deze functie om plaatjes van de server te laten laden
 * door de browser die je widget opent
 */

 /* function preload() {
  
 }
 */


/**
 * checkForDatabaseUpdate
 * Controleert of de database wijzingen heeft waarvan wij nog niet weten.
 * Verdere actie vereist bij reponse "Update needed"
 */
function checkForDatabaseChanges() {
  // zet het serverrequest in elkaar
  var request = new XMLHttpRequest();
  request.open('GET', `/api/checkchanges/${laatsteUpdateTimeStamp}`, true)
  request.onload = function () {
    if (request.status >= 200 && request.status < 400) {
      if (this.response == "Update needed") {
        console.log("Server geeft aan dat de database een update heeft die widget nog niet heeft");

        // roep ander update functie(s) aan:
        getTotalPresses();
      }
      else {
        // je kunt de code hieronder aanzetten, maar krijgt dan wel iedere seconde een melding
        // console.log("Widget is up to date");
      }
    }
    else {
        console.log("bleh, server reageert niet zoals gehoopt");
        console.log(this.response);
      }
  }

  // verstuur het request
  request.send()
}

/**
 * getTotalPresses
 * Vraagt het totaal aantal buttonPresses op
 */
function getTotalPresses() {
  // zet het serverrequest in elkaar
  var request = new XMLHttpRequest()
  request.open('GET', '/api/getTotalPresses', true)
  request.onload = function () {
    var data = JSON.parse(this.response);
    if (request.status >= 200 && request.status < 400) {
      console.log(`Totaal aantal buttonPresses = ${data.totalbuttonpresses} `);
      numberOfButtonPresses = data.totalbuttonpresses;
      var newTimeStamp = new Date(data.lasttimestamp).getTime()+1;

      // update indien nodig de timestamp
      if (laatsteUpdateTimeStamp < newTimeStamp) {
        laatsteUpdateTimeStamp = newTimeStamp;
      }
      
    }
    else {
        console.log("bleh, server reageert niet zoals gehoopt");
        console.log(this.response);
      }
  }

  // verstuur het request
  request.send()
}


function buttonPressed() {
  // zet het serverrequest in elkaar
  var request = new XMLHttpRequest()
  request.open('GET', '/api/addButtonPress', true)
  request.onload = function () {
    if (request.status >= 200 && request.status < 400) {
      console.log('ButtonPress doorgegeven aan server');
    }
    else {
        console.log("bleh, server reageert niet zoals gehoopt");
        console.log(this.response);
      }
  }

  // verstuur het request
  request.send()
}

function getScores() {
  // zet het serverrequest in elkaar
  var request = new XMLHttpRequest()
  request.open('GET', '/api/getScore', true)
  request.onload = function () {
    var data = JSON.parse(this.response);
    if (request.status >= 200 && request.status < 400) {
      console.log(`Score = ${data.totalbuttonpresses} `);
      scoreLinks = data.linksScore;
      scoreRechts = data.rechtsScore;
      var newTimeStamp = new Date(data.lasttimestamp).getTime()+1;

      // update indien nodig de timestamp
      if (laatsteUpdateTimeStamp < newTimeStamp) {
        laatsteUpdateTimeStamp = newTimeStamp;
      }
      
    }
    else {
        console.log("bleh, server reageert niet zoals gehoopt");
        console.log(this.response);
      }
  }

  // verstuur het request
  request.send()
}


function scoreReset() {
  // zet het serverrequest in elkaar
  var request = new XMLHttpRequest()
  request.open('GET', '/api/scoreReset', true)
  request.onload = function () {
    if (request.status >= 200 && request.status < 400) {
      console.log('Score reset wordt gedaan');
    }
    else {
        console.log("bleh, server reageert niet zoals gehoopt");
        console.log(this.response);
      }
  }

  // verstuur het request
  request.send()
}

/**
 * setup
 * de code in deze functie wordt eenmaal uitgevoerd,
 * als p5js wordt gestart
 */
function setup() {
  // Maak het canvas van je widget
  createCanvas(480, 200);

  // zet timeStamp op lang geleden zodat we alle recente info binnenkrijgen
  laatsteUpdateTimeStamp = new Date().setTime(0);

  // we vragen elke seconde of er iets is veranderd
  setInterval(checkForDatabaseChanges, 1000);
}


/**
 * draw
 * de code in deze functie wordt meerdere keren per seconde
 * uitgevoerd door de p5 library, nadat de setup functie klaar is
 */
function draw() {
    //check for changes
    checkForDatabaseChanges();



    // lay-out/uiterlijk widget
    background(0,0,0);
    fill(255, 255, 255);
    textSize(20);
    text("score", 190, 20);
    textSize(35);
    text(scoreLinks, 170, 60); 
    text(scoreRechts, 240, 60); 
}
