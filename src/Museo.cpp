#include "Museo.h"
#include<iostream>
using namespace std;

Museo::Museo()
{
    creamuseo();
}

void Museo::creamuseo()
{

    titoli[0]="Galleria A: Percorso Preistorico.";
    descrizioni[0]="Il percorso Preistorico comprende una serie di esposizioni di notevole importanza. Per maggiori descrizioni sui reperti presenti, consultare la guida elettronica";

    titoli[1]="Neuropteris sp.-Felci fossili-Carbonifero-Francia";
    descrizioni[1]="Queste piante raggiungevano un'altezza di cinque metri, con un tronco molto simile a quello delle attuali palme. Il fusto era formato in parte dalle basi foliari delle vecchie foglie, e possedeva radici aeree che crescevano in prossimita'  della base. Le fronde erano di diverso tipo: alcune erano dentellate, altre erano munite di foglioline arrotondate. A molte di queste foglie sono stati assegnati nomi diversi, come Neuropteris o Alethopteris. La prima era un tipo di foglia di grandi dimensioni, con un rachide percorso da striature longitudinali. In Alethopteris, invece, le venature erano poco visibili e quasi ad angolo retto, mentre il margine della foglia era dentellato.";

    titoli[2]="Allosaurus fragilis-Scheletro di Allosauro-Giurassico-Stati Uniti d'America";
    descrizioni[2]="Allosaurus e' un genere estinto di grande dinosauro teropode, vissuto tra i 155 e i 145 milioni di anni fa, durante il periodo Giurassico. I primi resti fossili furono ritrovati nel 1877, ad opera del paleontologo Othniel Charles Marsh, che ribattezzo' i resti come Antrodemus. Essendo uno dei primi dinosauri teropodi meglio conservati e piu' completi, questo animale ha piu' volte attirato l'attenzione di paleontologi e amanti dei dinosauri. L'Allosaurus era un predatore bipede di modeste dimensioni; il suo cranio era incredibilmente robusto e compatto e armato di una moltitudine di denti. La lunghezza di un esemplare adulto non doveva essere inferiore agli 8,5 metri  di lunghezza, anche se alcuni resti frammentari suggeriscono dimensioni maggiori, con esemplari che avrebbero potuto raggiungere i 12 metri di lunghezza.";

    titoli[3]="Coproliti di dinosauri - Epoche varie - Stati Uniti d'America";
    descrizioni[3]="Il termine coprolite deriva dal greco kopros (sterco) e la­thos (pietra) e indica un escremento, prodotto da un animale vissuto nel passato, che si e' fossilizzato. Dall'analisi di questi reperti, si possono ricavare informazioni sulle abitudini alimentari e l'habitat nel quale l'animale viveva. Per esempio, la presenza di semi, foglie, corteccia o radici indica che l'escremento e' stato prodotto da un erbivoro, mentre se si individuano frammenti di ossa, artigli o tendini l'animale era un carnivoro.";

    titoli[4]="Pterodactylus kochi-Rettile volante-Giurassico-Solnhofen (Germania)";
    descrizioni[4]="Pterodactylus e' un estinto genere di pterosauro, i cui membri sono popolarmente chiamati ''pterodattili''. Attualmente, il genere contiene una singola specie, Pterodactylus antiquus, che oltre ad essere la specie tipo e' anche il primissimo genere di pterosauro mai rinvenuto. I principali ritrovamenti di resti fossili di questo animale sono stati rinvenuti principalmente, nei Calcari di Solnhofen, di Baviera, in Germania, risalenti alla fine del periodo Giurassico, circa 150,8-148-500 milioni di anni fa, anche se alcuni resti frammentari sono stati rinvenuti anche in altre aree in Europa e in Africa. Questo animale era un predatore che probabilmente si cibava soprattutto di pesci e piccoli invertebrati marini. Come tutti gli pterosauri, anche le ali dello Pterodactyluserano formate da una membrana di pelle che si estendeva dalla fine del quarto dito della ''mano'' fino agli arti posteriori. L'ala era supportata, ulteriormente, internamente da fibre di collagene ed esternamente da strutture cheratinose.";

    titoli[5]="Tirannosauro vissuto nel Cretaceo superiore(tirannosauridi).";
    descrizioni[5]="Il tirannosauro  era un dinosauro vissuto nel Cretaceo superiore appartenente alla famiglia dei tirannosauridi. Visse in nordamerica, che anticamente era un continente isolato nominato Laramidia. Il Tyrannosaurus era molto piu' diffuso geograficamente degli altri tirannosauridi. I suoi fossili si trovano in una varietÃ  di formazioni risalenti all' epoca Maastrichtiana del Cretaceo superiore, circa 68-66 milioni di anni fa. Fu una delle specie degli ultimi dinosauri non-aviani viventi quando si ebbe l' estinzione di massa del Cretaceo-Paleocene, che determino' la scomparsa dei dinosauri propriamente detti. ";

    titoli[6]="Galleria B: Percorso Romano.";
    descrizioni[6]="Come testimonianza di questo periodo storico potrete ammirare antichi affreschi. Per ulteriri dettagli, consultare la guida elettronica";

    titoli[7]="Numa Pompilio istituisce il culto delle Vestali e dei sacerdoti(1636-1638)";
    descrizioni[7]="Al centro della scena, sullo sfondo di un grandioso scorcio architettonico, arde sull' altare il fuoco sacro che le Vestali dovevano custodire sempre acceso.";

    titoli[8]="Ritrovamento della Lupa con Romolo e Remo (1596)";
    descrizioni[8]="Faustolo scopre sotto i rami di un fico, sulla riva del Tevere, la Lupa che allatta Romolo e Remo. Nella figura della lupa e' evidente il richiamo alla Lupa capitolina conservata nel palazzo e simbolo della citta'.";

    titoli[9]="Combattimento degli Orazi e Curiazi(1612-1613)";
    descrizioni[9]="Episodio della guerra di Roma contro la vicina citta' di Albalonga che si concluse con un duello tra i rappresentanti di Roma, gli Orazi, e quelli di Albalonga, i Curiazi. Gli eserciti contendenti assistono alla scena finale del duello, quando l' ultimo degli Orazi sta per colpire l' ultimo degli avversari ";

    titoli[10]="Ratto delle Sabine (1635-1636)";
    descrizioni[10]="In primo piano e' il gruppo delle donne Sabine rapite dai Romani per popolare la citta'  da poco fondata. L'affresco, eseguito dopo circa venti anni di interruzione, condivide con le ultime due scene una tecnica pittorica piu' rapida e sommaria, tipica della tarda maniera del Cavalier d' Arpino.";

    titoli[11]="Battaglia di Tullo Ostilio contro i Veienti e i Fidenati(1597-1601)";
    descrizioni[11]="Con vivacita' e' rappresentato un episodio della guerra di espansione intrapresa dai Romani contro le cittÃ  vicine al tempo di Tullo Ostilio, terzo re di Roma.";

    titoli[12]="Galleria C: Ritrovamenti del periodo che va dal 200-300 a.C.";
    descrizioni[12]="Sono stati ritrovati numerosi reperti risalenti a questa epoca, alcuni dei quali sono presenti all'interno della nostra galleria. Per maggiori descrizioni, consultare la guida elettronica";

    titoli[13]="Stele funeraria del tipo a ''falsa porta'' a nome di Sameri";
    descrizioni[13]="La stele a '' falsa porta ''  e'  un elemento funerario tipico delle sepolture dell' Antico Regno ed e'  costituita da due o piu' montanti laterali e da un architrave sotto cui e'  scolpita una stuoia arrotolata a suggerire l' idea di una porta accessibile all' anima del defunto. Questa stele appartiene ad un funzionario di nome Sameri, membro di una famiglia di cortigiani molto vicina al faraone, e gli dedicata dal padre Urkaptah, che include nel dono anche la moglie e gli altri figli. Sameri e' rappresentato con la tecnica del rilievo ad incavo sull' architrave della â€œfalsa portaâ€�, mentre siede in compagnia della madre Henutes davanti a una tavola ricolma di vasellame da mensa e di alimenti (pani, anatre giÃ  spennate, tranci di carne bovina, etc.) utili per la sua sopravvivenza ultraterrena che lâ€™iscrizione in caratteri geroglifici sottostante completa per forza magica. Lâ€™importanza del pane, quale alimento base della dieta egiziana, appare evidente, anche se non e'  possibile differenziare le varie tipologie di pane elencate per qualitÃ  di ingredienti, modalitÃ  di impasto e di cottura.";

    titoli[14]="Rilievo con scena di libagione ";
    descrizioni[14]="Il rilievo, collocato in origine alle pareti di una tomba, mostra una scena di libagione. La â€œsignora della casaâ€� Nubi, proprietaria della sepoltura, siede su una bassa sedia decorata con zampe di gatto mentre riceve l'offerta funeraria di acqua e di vino da sua figlia Kiki, in piedi davanti a lei. Altri cibi, tra i quali un mazzetto di porri e varie cucurbitacee, sono raccolti allâ€™interno di un profondo bacile alle spalle di Kiki allo scopo di nutrire in eterno la defunta. L'eleganza e la morbidezza delle figure, come la raffinatezza dei costumi rivelano l'agiatezza di vita della dama Nubi, tipica dell' Egitto del Nuovo Regno. Entrambe le donne indossano lunghi abiti la cui semplicitÃ  contrasta con la resa accurata dei gioielli, visibili alle braccia, al collo e alle orecchie,e delle pesanti parrucche adorne di nastri coroncine di fiori e cono di unguento profumato.";

    titoli[15]="Rilievo dalla tomba di Horemheb con scena di lavoro nei campi dell'oltretomba ";
    descrizioni[15]="Il rilievo, proveniente da una delle tre cappelle di culto annesse alla tomba menfita del generale Horemheb, e' costituito da due frammenti parietali combacianti ed e' suddiviso in quattro fasce orizzontali scolpite a bassorilievo. E' probabile che quella in alto, di cui sopravvive solo la parte inferiore, contenesse l'omaggio di Horemheb alle divinitÃ  funerarie. Nei due registri centrali, meglio conservati, Horemheb e' colto in momenti diversi: seduto in compagnia della sua â€œanimaâ€� akh dalle sembianze di uccello appollaiato su un trespolo davanti a una tavola piena di pani di varia forma, tranci di carne bovina e altri cibi destinati al pasto funebre del defunto; in piedi mentre governa alcuni buoi che calpestano un mucchio di spighe di cereale per separare i chicchi dalla pula; in piedi, dietro un aratro trainato da due buoi, intento a dissodare il terreno da coltivare. In basso, Horemheb e'  nuovamente seduto davanti a una tavola stracolma di offerte e, a raccolto ultimato, riceve in dono alcuni mannelli di lino da parte di tre contadini. Tutte queste scene, ispirate al capitolo 110 del Libro dei Morti, ci mostrano Horemheb al lavoro nei campi dellâ€™oltretomba per garantirsi la sopravvivenza eterna. Il serpente ureo, simbolo di regalitÃ , che orna la sua fronte, fu scalpellato in un secondo momento, solo quando Horemheb divenne faraone dâ€™Egitto alla fine della XVIII dinastia.";

    titoli[16]="Rilievo con la dea Renenutet";
    descrizioni[16]="Il rilievo proviene dalla tomba di uno scriba di nome Amenemhat, vissuto agli inizi del Nuovo Regno, prima del faraone Akhenaton, durante il cui governo il nome del dio Amon fu spesso cancellato, come in questo caso. Sul rilievo sono raffigurate due tipiche attivitÃ  agricole: nella parte alta, alcuni contadini puliscono il grano lanciandolo in aria con sessole di legno per separare i chicchi dalla pula, mentre un uomo offre loro da bere con profonde ciotole emisferiche, riempite in un grande vaso panciuto alle sue spalle. Nel registro inferiore si procede alla misurazione del cereale ormai pulito e accumulato di fronte alla dea delle messi Renenutet, in forma di serpente cobra. Scene di questo tipo, sia dipinte che a rilievo, sono piuttosto comuni nellâ€™arte egiziana a partire dall'Antico Regno.";

    titoli[17]="Sarcofago a cassa a nome di Irinimenpu ";
    descrizioni[17]="La decorazione principale di questo sarcofago destinato al corredo funerario di un egiziano di nome Irinimenpu consiste in una serie di pannelli a 'facciata di palazzo', un motivo ripreso dall'architettura funararia dell'Antico Regno, che rende il sarcofago simile a una dimora eterna. Su uno dei lati lunghi della cassa, in posizione centrale, sono raffigurate numerose offerte alimentari (pani, ortaggi, frutti, tranci di carni bovine, volatili giÃ  spennati, contenitori per liquidi, etc.), perche' il defunto possa nutrirsene per forza magica nella vita ultraterrena. Sullo stesso lato,a una delle estremita', e' dipinta una porta chiusa, sopra la quale sono collocati due occhi che indicano la presenza all'interno della testa della mummia e allo stesso tempo rappresentano una protezione magica per il corpo del defunto. L'ottimo stato di conservazione del legno e dei vivaci colori utilizzati per decorarlo si deve al clima caldo e asciutto dell'Egitto,oltre che alla collocazione originaria del sarcofago nell'ambiente protetto della sepoltura.";

    titoli[18]="Galleria D: Percorso sulla Magna Grecia";
    descrizioni[18]="In questa galleria verrai guidato nell'esplorazione del percorso sulla Magna Grecia. La Magna Grecia e' l'area geografica della penisola italiana meridionale che fu anticamente colonizzata dai Greci a partire dall' VIII secolo a.C.. Di questa civilta' possediamo numerose sculture e reperti Per maggiori descrizioni sui reperti presenti, consultare la guida elettronica";

    titoli[19]="Testa in marmo di Eracle";
    descrizioni[19]="Probabilmente una copia del colosso bronzeo creato da Lisippo a Tara alla fine del IV secolo AC.";

    titoli[20]="Stele figurata in marmo con defunto in nudita'  eroica.";
    descrizioni[20]="Raffigurato nell'atto di offrire una melagrana ad un serpente, simbolo funerario delle divinita'  infernali.";

    titoli[21]="Statua marmorea del II secolo d.C. di genio carpoforo (portatore di frutti).";
    descrizioni[21]="Proveniente dall'area delle Terme e relativo alla decorazione scultorea delle stesse.";

    titoli[22]="Specchio in argento, con doratura a caldo.";
    descrizioni[22]="E' raffigurata l'immagine di una Musa, o di Afrodite, circondata da Eroti. Dalla tomba degli Ori di Canosa.";

    titoli[23]="I Bronzi di Riace";
    descrizioni[23]="I Bronzi di Riace sono due statue di bronzo di provenienza greca o magnogreca o siceliota, databili al V secolo a.C. pervenute in eccezionale stato di conservazione. Le due statue, rinvenute il 16 agosto 1972 nei pressi di Riace, in provincia di Reggio Calabria sono considerate tra i capolavori scultorei piu' significativi dell'arte greca, e tra le testimonianze dirette dei grandi maestri scultori dell'eta' classica. Le ipotesi sulla provenienza e sugli autori delle statue sono diverse, ma non esistono ancora elementi che permettano di attribuire con certezza le opere ad uno specifico scultore. I Bronzi si trovano al Museo nazionale della Magna Grecia di Reggio Calabria, luogo in cui sono stati riportati il 12 dicembre 2015, dopo la rimozione e il soggiorno per tre anni (con annessi lavori di restauro) presso Palazzo Campanella, sede del Consiglio Regionale della Calabria a causa dei lavori di ristrutturazione dello stesso museo. I Bronzi sono diventati uno dei simboli della cittÃ  stessa.";

    titoli[24]="Entrata museo delle scienze";
    descrizioni[24]="Benvenuto nel museo delle scienze. Hai a disposizione una serie di gallerie visitabili, ognuna delle quali. Presenta diversi percorsi con varie tipologie di esposizioni.";

    StanzaMuseo stanza;
    stanza.setdescrizione(descrizioni[24]);
    stanza.settitolo(titoli[24]);
    typename Grafo<StanzaMuseo,unsigned char>::nodo nodo1,nodo2,nodo3,nodo4,nodo5,nodo6,nodo7,nodo8,nodo9,nodo10,nodo11,nodo12,nodo13,nodo14,
    nodo15,nodo16,nodo17,nodo18,nodo19,nodo20,nodo21,nodo22,nodo23,nodo24,nodo0;

    grafomuseo.insnodo(nodo24);
    grafomuseo.scrivinodo(stanza,nodo24);

    // setto la stanza iniziale e corrente nel grafo.
    grafomuseo.insnodo(stanzacorrente);
    grafomuseo.insnodo(stanzainiziale);
    setstanzacorrente(nodo24);
    grafomuseo.scrivinodo(stanza,stanzainiziale);

    stanza.setdescrizione(descrizioni[0]);
    stanza.settitolo(titoli[0]);
    grafomuseo.insnodo(nodo0);
    grafomuseo.scrivinodo(stanza,nodo0);


    stanza.setdescrizione(descrizioni[6]);
    stanza.settitolo(titoli[6]);
    grafomuseo.insnodo(nodo6);
    grafomuseo.scrivinodo(stanza,nodo6);


    stanza.setdescrizione(descrizioni[12]);
    stanza.settitolo(titoli[12]);
    grafomuseo.insnodo(nodo12);
    grafomuseo.scrivinodo(stanza,nodo12);


    stanza.setdescrizione(descrizioni[18]);
    stanza.settitolo(titoli[18]);
    grafomuseo.insnodo(nodo18);
    grafomuseo.scrivinodo(stanza,nodo18);

    stanza.setdescrizione(descrizioni[1]);
    stanza.settitolo(titoli[1]);
    grafomuseo.insnodo(nodo1);
    grafomuseo.scrivinodo(stanza,nodo1);

    stanza.setdescrizione(descrizioni[2]);
    stanza.settitolo(titoli[2]);
    grafomuseo.insnodo(nodo2);
    grafomuseo.scrivinodo(stanza,nodo2);

    stanza.setdescrizione(descrizioni[3]);
    stanza.settitolo(titoli[3]);
    grafomuseo.insnodo(nodo3);
    grafomuseo.scrivinodo(stanza,nodo3);

    stanza.setdescrizione(descrizioni[4]);
    stanza.settitolo(titoli[4]);
    grafomuseo.insnodo(nodo4);
    grafomuseo.scrivinodo(stanza,nodo4);

    stanza.setdescrizione(descrizioni[5]);
    stanza.settitolo(titoli[5]);
    grafomuseo.insnodo(nodo5);
    grafomuseo.scrivinodo(stanza,nodo5);

    stanza.setdescrizione(descrizioni[7]);
    stanza.settitolo(titoli[7]);
    grafomuseo.insnodo(nodo7);
    grafomuseo.scrivinodo(stanza,nodo7);

    stanza.setdescrizione(descrizioni[8]);
    stanza.settitolo(titoli[8]);
    grafomuseo.insnodo(nodo8);
    grafomuseo.scrivinodo(stanza,nodo8);

    stanza.setdescrizione(descrizioni[9]);
    stanza.settitolo(titoli[9]);
    grafomuseo.insnodo(nodo9);
    grafomuseo.scrivinodo(stanza,nodo9);

    stanza.setdescrizione(descrizioni[10]);
    stanza.settitolo(titoli[10]);
    grafomuseo.insnodo(nodo10);
    grafomuseo.scrivinodo(stanza,nodo10);

    stanza.setdescrizione(descrizioni[11]);
    stanza.settitolo(titoli[11]);
    grafomuseo.insnodo(nodo11);
    grafomuseo.scrivinodo(stanza,nodo11);

    stanza.setdescrizione(descrizioni[13]);
    stanza.settitolo(titoli[13]);
    grafomuseo.insnodo(nodo13);
    grafomuseo.scrivinodo(stanza,nodo13);

    stanza.setdescrizione(descrizioni[14]);
    stanza.settitolo(titoli[14]);
    grafomuseo.insnodo(nodo14);
    grafomuseo.scrivinodo(stanza,nodo14);

    stanza.setdescrizione(descrizioni[15]);
    stanza.settitolo(titoli[15]);
    grafomuseo.insnodo(nodo15);
    grafomuseo.scrivinodo(stanza,nodo15);

    stanza.setdescrizione(descrizioni[16]);
    stanza.settitolo(titoli[16]);
    grafomuseo.insnodo(nodo16);
    grafomuseo.scrivinodo(stanza,nodo16);

    stanza.setdescrizione(descrizioni[17]);
    stanza.settitolo(titoli[17]);
    grafomuseo.insnodo(nodo17);
    grafomuseo.scrivinodo(stanza,nodo17);

    stanza.setdescrizione(descrizioni[19]);
    stanza.settitolo(titoli[19]);
    grafomuseo.insnodo(nodo19);
    grafomuseo.scrivinodo(stanza,nodo19);

    stanza.setdescrizione(descrizioni[20]);
    stanza.settitolo(titoli[20]);
    grafomuseo.insnodo(nodo20);
    grafomuseo.scrivinodo(stanza,nodo20);

    stanza.setdescrizione(descrizioni[21]);
    stanza.settitolo(titoli[21]);
    grafomuseo.insnodo(nodo21);
    grafomuseo.scrivinodo(stanza,nodo21);

    stanza.setdescrizione(descrizioni[22]);
    stanza.settitolo(titoli[22]);
    grafomuseo.insnodo(nodo22);
    grafomuseo.scrivinodo(stanza,nodo22);

    stanza.setdescrizione(descrizioni[23]);
    stanza.settitolo(titoli[23]);
    grafomuseo.insnodo(nodo23);
    grafomuseo.scrivinodo(stanza,nodo23);

    // Inserisco gli archi fra le stanze

    grafomuseo.insarco(nodo0,nodo6);
    grafomuseo.insarco(nodo6,nodo0);


    grafomuseo.insarco(nodo6,nodo12);
    grafomuseo.insarco(nodo12,nodo0);


    grafomuseo.insarco(nodo12,nodo18);
    grafomuseo.insarco(nodo18,nodo12);


    grafomuseo.insarco(nodo0,nodo18);
    grafomuseo.insarco(nodo18,nodo0);



    grafomuseo.insarco(nodo24,nodo0);
    grafomuseo.insarco(nodo0,nodo24);


    grafomuseo.insarco(nodo24,nodo6);
    grafomuseo.insarco(nodo6,nodo24);



    grafomuseo.insarco(nodo24,nodo12);
    grafomuseo.insarco(nodo12,nodo24);



    grafomuseo.insarco(nodo24,nodo18);
    grafomuseo.insarco(nodo18,nodo24);

    grafomuseo.insarco(nodo0,nodo1);
    grafomuseo.insarco(nodo1,nodo0);


    grafomuseo.insarco(nodo0,nodo2);
    grafomuseo.insarco(nodo2,nodo0);


    grafomuseo.insarco(nodo3,nodo0);
    grafomuseo.insarco(nodo0,nodo3);


    grafomuseo.insarco(nodo0,nodo4);
    grafomuseo.insarco(nodo4,nodo0);


    grafomuseo.insarco(nodo0,nodo5);
    grafomuseo.insarco(nodo5,nodo0);


    grafomuseo.insarco(nodo6,nodo7);
    grafomuseo.insarco(nodo7,nodo6);


    grafomuseo.insarco(nodo6,nodo8);
    grafomuseo.insarco(nodo8,nodo6);


    grafomuseo.insarco(nodo6,nodo9);
    grafomuseo.insarco(nodo9,nodo6);


    grafomuseo.insarco(nodo6,nodo10);
    grafomuseo.insarco(nodo10,nodo6);


    grafomuseo.insarco(nodo6,nodo11);
    grafomuseo.insarco(nodo11,nodo6);


    grafomuseo.insarco(nodo12,nodo13);
    grafomuseo.insarco(nodo13,nodo12);


    grafomuseo.insarco(nodo12,nodo14);
    grafomuseo.insarco(nodo14,nodo12);


    grafomuseo.insarco(nodo12,nodo15);
    grafomuseo.insarco(nodo15,nodo12);


    grafomuseo.insarco(nodo12,nodo16);
    grafomuseo.insarco(nodo16,nodo12);


    grafomuseo.insarco(nodo12,nodo17);
    grafomuseo.insarco(nodo17,nodo12);


    grafomuseo.insarco(nodo18,nodo19);
    grafomuseo.insarco(nodo19,nodo18);


    grafomuseo.insarco(nodo18,nodo20);
    grafomuseo.insarco(nodo20,nodo18);


    grafomuseo.insarco(nodo18,nodo21);
    grafomuseo.insarco(nodo21,nodo18);


    grafomuseo.insarco(nodo18,nodo22);
    grafomuseo.insarco(nodo22,nodo18);


    grafomuseo.insarco(nodo18,nodo23);
    grafomuseo.insarco(nodo23,nodo18);


}

typename Grafo<StanzaMuseo,unsigned char>::nodo Museo::getstanzacorrente()
{

    return(stanzacorrente);

}

typename Grafo<StanzaMuseo,unsigned char>::nodo Museo::getiniziale()
{

    return(stanzainiziale);

}

void Museo::setstanzacorrente(typename Grafo<StanzaMuseo,unsigned char>::nodo s)
{

    stanzacorrente = s;

}

Lista<typename Grafo<StanzaMuseo,unsigned char>::nodo> Museo::getstanzeadiacenti()
{
  return grafomuseo.adiacenti(stanzacorrente);
}

//Implementazione di Museom.h aggiunta da ANTONIO PASTORELLI


// Operatori Aggiunti da Graziano Montanaro
StanzaMuseo Museo::leggiStanza(typename Grafo<StanzaMuseo, unsigned char>::nodo stanza)
{
    return grafomuseo.legginodo(stanza);
}

void Museo::scriviStanza(typename Grafo<StanzaMuseo, unsigned char>::nodo stanza, const StanzaMuseo& info)
{
    grafomuseo.scrivinodo(info, stanza);
}



