# Verslag eindopdracht 6V
### gemaakt door Kars K, Kars H, Lucas K, Amir, Daan N, Maarten en Wesley

## Inleiding
Wij zijn [zie namen hierboven] en wij zijn groep 5 voor de eindopdracht voor informatica.
Ik ben Wesley, degene die verantwoordelijk is voor de Git / Verslag.
Kars K heeft zich voornamelijk bezig gehouden met de Website.
Kars H heeft zich aan de andere kant bezig gehouden met het gedeelte "Server" en een stukje Constructie.
Daarnaast hebben Daan N en Amir hun tijd besteed aan de Knikkerbaan / Constructie.
Lucas K heeft voornamelijk de Arduino gecodeerd en in elkaar gezet, en natuurlijk onderzocht hoe de onderdelen werken.
Maarten heeft zich ten slotte bezig gehouden met de planning en met een beetje Constructie en Arduino.

Al in al hebben allemaal wel nagedacht over wat ons als groepje het leukst leek om te doen qua knikkerbaan.

## Idee
Ons idee was om een knikkerbaan te maken waarbij er twee kanten zijn die een soort tegen elkaar racen om wie het snelste beneden is.
Aan het begin krijgt onze knikkerbaan natuurlijk de knikkers binnen via een andere knikkerbaan of handmatig.
Deze knikkers worden gedistrubueerd via een trechter naar de linker- en rechterkant van de baan waar ze tegen elkaar racen.
Ons idee voor de twee knikkerbanen, links en rechts, is om ze indentiek te bouwen, maar op dit moment is dat nog slechts een idee.
We hadden ook het idee om een looping te doen, maar eerst zagen we dat "luchtpompen" moeilijk of onmogelijk te krijgen is.
We moesten daarom een andere solutie vinden voor de looping of halve looping en dat is om solenoids te gebruiken om de knikkers snelheid te geven.
Daarna komen de knikkers in de andere banen andere obstakels tegen die waarschijnlijk via een normale zigzag gaat.
Via de webpagina kan je ook op knoppen drukken met een interval om een van de kanten te saboteren voor een x aantal seconden.

tl;dr
13-12-2020: Ons idee nu is om met een solenoid in plaats van een luchtpomp de knikkers op twee tegen elkaar racende banen
af te schieten en dat je via de website een van de twee kanten kan saboteren. Daarnaast is er een sorteersysteem aan het begin.

26-02-2021
Door tijdsnood hebben we het idee helemaal door elkaar gehaald. We hebben gekozen om niet meer grootschalige sabotage te doen, maar wel om twee kanten te maken en een klein beetje sabotage. Je kan dus niet meer een kant vernanderen. De knikkers worden bovenaan opgevangen in een bakje, komt in een sorteeldeel die kan ronddraaien via code.
Via een onderbrekingssensor aan het begin wordt het sorteeldeel omgedraaid (links/rechts). en via servo's aan het begin worden de knikkers tegelijk losgelaten (beide moeten
aanwezig zijn om het goed te laten starten). Via knoppen kan je de andere kant saboteren (kleine sabotage zoals gezegd) via nog een servo. Ten slotte zitten er nog meer
onderbrekingssensoren aan het einde die, makkelijk gezegd, het einde markeren van de baan.



## Planning en daadwerkelijke uitvoering
Onze opdracht is als volgt gepland:
Via Whatsapp en Discord plannen we momenten om te overleggen of we overleggen on the spot.
Iedereen houdt zich bezig met hun taak en kunnen elkaar vragen voor hulp. We zijn dus niet gelimiteerd aan onze eigen rol.
Wesley (Git) heeft bijvoorbeeld geholpen met het onderzoeken van een sensor, en Kars H (Server) heeft geholpen met de knikkerbaan in elkaar zetten.

### sprint 3
Dit was natuurlijk een sprint waar we vooral ideeën moesten krijgen en een soort moesten inkomen met het idee.
Zoals gezegd was het vooraf het idee om de knikker af te schieten met een luchtpomp, maar die bleek moeilijk te krijgen zijn.
We kwamen rond het einde van deze sprint achter dat het ons leuker leek om twee knikkers via een sorteersysteem tegen elkaar te laten racen.

### sprint 4
Hier dachten we wat meer aan uitbreidingen op de knikkberbaan, zoals het saboteren en dat we een solenoid konden gebruiken,
in plaats van de luchtpomp. Daarnaast moesten we ook gaan werken aan het praktische gedeelte en veel minder aan de theorie.

### sprint 5
Er gebeurde hier vrij weinig in het algemeen, klein beetje overleg en beginnetjes aan het ontwerp op papier en in theorie en een beetje code.

### sprint 6
Hier moesten we echt aan de bak want we hadden niet veel code en fysieks gedaan. In het algemeen kun je zeggen dat we in de laatste sprint alles hebben gedaan.
Nieuw ontwerp, code af, fysieke baan af, etc etc etc. Veel overleg was hier nodig via de Whatsapp en Discord, over hoe we het allemaal voor elkaar zouden (moeten) krijgen. Uitendelijk hebben (bijna) alles voor elkaar gekregen zoals we wilden en planden precies voor de presentatie.



## Technische verantwoording
Ons communicatieprotocol werkt zo:
We hebben natuurlijk van tevoren een groepsapp gemaakt waar we allemaal onze voorkeur gaven over welk "expert" we wilden zijn
en wie de reserve experts worden van wat. Uiteindelijk heeft Kars K ons allemaal (als leider van de groep) ingedeeld in het een en ander.
Na de groepsapp leek het ons ook best handig om wat "echt" verbaal contact te hebben in plaats van dat slome Whatsapp,
en daarom maakten we een Discordserver aan en hebben we daar van tijd tot tijd besproken.
We hadden niet echt deadlines of regels voor dingen gemaakt, en we gingen vooral uit onszelf ons eigen weg.
Dat we geen regels maakten of iets wat daarop lijkt betekende overigens niet dat we niet wisten wat we moesten doen.
We hadden aan het begin namelijk al aan elkaar duidelijk gemaakt en verteld wie en wat, alleen zoals gezegd geen duidelijke wanneer.

## Reflectie
#### Wesley
Ik vond het idee erg leuk was.Een knikkerbaan samengevoegd met vele andere informatica onderwerpen zoals een Website en een Arduino, dat alles combineert wat je
de vorige jaren inclusief dit jaar hebt geleerd. Het enige wat wel beter kon was zowel de tijdsplanning alsde echte motiviatie krijgen. Ik hoor van
velen dat ze niet klaar zijn, en pas 1 of 2 dagen van tevoren zijn begonnen. Het idee was goed in mijn opinie, de echte uitvoering kan veel beter.

#### Maarten
Ik vond ook het idee van een knikkerbaan maken leuk. Ons plan leek me ook goed, alleen was de uitvoering wat minder. Uiteindelijk hebben we niet een fysiek werkende knikkerbaan 
wat jammer is. Dit komt deels door corona en de weinige mogelijkheden om de baan te bouwen en deels door slechte planning en de planning niet nakomen. Ook had de samenwerking 
en communicatie beter gekunt.

#### Kars K
Het is een druk jaar, zowel door corona als door het examenjaar zelf. Hierdoor heb je niet echt door hoe snel het gaat en gaat het mis met de planning, ook was motivatie een probleem. Dit zorgt voor een nogal belabberd eindproduct, als je het zo kan noemen. Ik zelf ben tegen het einde van het project niet in de meest gemotiveerde stemming en omdat ik zelf eerder niet doorhad hoe snel het allemaal wel ging heb ik er eerder niks aan gedaan. Het stuk wat ik zou gaan doen is eigenlijk nauwelijks werkend en hooguit een framework. Samenwerken in het project kon ook beter, doordat ons groepje verspreid zat door twee klassen heen kon er een desynchronisatie van kennis komen, omdat niet altijd in het zelfde les zat. Hierdoor moest alles over Whatsaap en discord wat nogal stroefjes verliep. Ik denk dat dit project veel beter had gekund met de juiste planning en communicatie.

#### Amir
Het project waar we een knikkerbaan zouden bouwen met behulp van Arduino leek mij erg leuk en daar was ik zeer benieuwd naar. Ik had veel zin om hieraan te werken, omdat ik de knikerbaan heel graag werkend wilde zien. De knikkerbaan bouwen vond ik erg leuk en dat geld ook voor de code in Arduino. De communicatie mocht wel wat beter, we moesten wat meer met elkaar communiceren en betere afspraken maken. Ik vind het ook jammer dat we niet een volledig eindproduct hebben kunnen maken, omdat ik het plan erg leuk vond en het project graag werkend had willen zien.


## Slot
