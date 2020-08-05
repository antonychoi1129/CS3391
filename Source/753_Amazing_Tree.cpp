#include<iostream>
#include<string.h>
using namespace std;

int XORvalue;
int amazingTree(char* tree,int opPos, int clPos) {
	int weight = 0;

	int openers = 1;
	bool isNode = true;	//Can be a layer, than dont XOR it.
	if (clPos - opPos <= 1) weight = 1;
	else
		for (int i = opPos+1; i <= clPos; i++) {
			if (tree[i] == '(') openers++;
			else openers--;

			if (openers == 0) {
				if (isNode && i < clPos) isNode = false;
				if (i - opPos <= 1)
					weight += amazingTree(tree, opPos, i);
				else if (isNode)
					weight += 1 + amazingTree(tree, opPos + 1, i - 1);
				else
					weight += amazingTree(tree, opPos, i);
				opPos = i + 1;
			}
		}

	if(isNode) XORvalue ^= weight;
	return weight;
}

int main() {
	char line[1000];
	while (cin>>line) {
		XORvalue = 0;
		amazingTree(line, 0, strlen(line)-1);
		printf("%i\n",XORvalue);
	}
	return 0;
}

/*
                                   `--.                                                             
                                   `shodmdso+-/`                                                    
                                   `yys/odmmds+`                                                    
                                   /o/smd/++y:`              `/o/-                                  
                                  `/:NNm/.yyym:             `yhysh+                                 
                                  `syhNmo.-yNN+      .++.   `hhhsso                                 
                      --`       ./sNddmNdoomh:`     /ydNd+`  shhos+                                 
                     .mmdos:-  .dNNMNdddmmNMNh+  .. /yydddyo-+yhoys.                                
                     -dNmyNmydohmmNNNmmdmNMNNNm. `hs:yyyddyydhhsyss+                                
                     :ydmNhddMNNMNNNNmNmNmNMMMNdssyhdmdyydhymds+ysys`                               
                     `:oydhmdSTUPIDTREENNNNMNhhdmhhshddyhhdhhmyossys`                               
                       +mmNNdmMmmNMMmNMNNMMMm```-/shydhyhhddsyhhy+y:                                
                       :sosyhNMNdNMMNmNNMNNNy     -yhddhddNMmhyhhhh`                                
                        ``dNNMyssmNmmNNMMNNm`      .yhsshdmdhyo+shy`                                
                          +NMNy:/dmdmNNMMNNh`   ``.-yddsydyyyys+os/                                 
                      `-.  sdmmmdmmmdmNNNNNmhdhhhdmmNmyhhhsyyyo/os.                                 
                       -/s/yhdddddddddmNNNNmmNMMNhhdmhyyyydhyso/y+     ``                           
              ``      ./+hmhdNNNmdhhhmmmmmmdmNNmhdmMdhdsyyhshhyos/  ```-                            
              -o`  `-+ydmhddNMNhhdmddyhhyhdNMMNNNmmhhhNdhdyshhosyho::ooy::-.                        
             `so.-oyhdhhydNddNmhsydhhyyhdmmmNmmmmNmhmhNmdmydhyyyNNNmyhh:.`                          
             +myydmhhddhdmmhhhhdhdmdmdhyyhdhhihatetreeNdmdhmmdmshyhNdyys-                           
           `/mNhddhyydhhdhhhyhdddmdddddmmNyhhhhhhhhhhdmmNdyyhyyshsodNhsys                           
          -yNMMmNmmmy+:-:---:/+ohddhhhMNddhhhhyyyyyyhyymNyyyysyysyysdmhy-                           
   ``` `./hNMMMMMMMy            /hhhyyNyyyhhhhhyyyyhhyhNdhysssysshdyssy:                            
 ````/+shhNMMNNNNNy`            .sdNyhdhhhhhhdddhyysyyhdysosyyyyhdhhhs.                             
 .yoyohdmmNNNmmmd+              -ydMhNhdhhhhhhyysyyyyhmsoooyysyyhmhho`                              
 `.`/shmdNmmmh+-`               :yhNyNmmymmdddhyyyyosymsosyyyyhmNmmh.                               
   -symmddmms.                  :ydNmdNmdhdhhyyyyyyyyyysydyy+-Nmmhhy`                    .:-        
 .smmdmNhds-                    +hdhmmNNmhdddddhhhhydNdhmyy:``dNmdhyys-`               `/s-         
-oyyyhhdd+                    -:shdmddNmdhmddhdddhhyhymNdy- ./dNNNmmNNNh/`           `:yy`          
.osssyoss-                    --/hdhNNNmdymMmdhyyhhyyddhs/    :mNNNNNNNmmdo-`       -sdm.           
 yddmNdd+`  ``-.               -ymddhddmNdmNhydddhhhdyyo.     `.smNNNNNNNmmNdyo/--/yddhd:`          
`oshdddy//osyyy/.            `+dhhddmmdddmmMmmddmmdyhhs`         `:/ymmmNNNNNNNNNNNNmmmdh+:`   `-.` 
 ``-oshdddhho:`              /Nihatetreemmmmmddddhhddh:              ..-+ymmmmmmmmmmmNNmdhhhs/` `-s-
    `::::-.                  yMNNdmmNmmmmdmNmddhdmhhhd.                    `...-:ohmmNmNmddmNms/oyh-
                            -mmNNdddmmmmNmdNNMmdyyhmNh:                            :ymddNNmhhhyhs.  
                             yNMmhddhddhhddmNNhsyyhdmdo                              -sydNmyo````   
                             hNMNymNhhhhhhhhyhmyhddyysh-                               ````         
                            -dNMNydMhymNdyhhdhdhdmdhyyhy/                                           
                            :mMNNyhNdyhMmysymhmNNmdhysyhh+                                          
                            :mNmNdhdhhddsoshdNNMNMmyhhyhmy+                                         
                            :hmmNdyhmmmhs+ymdNMMNmNNdyymhdy.                                        
                            -hddNyohNNhy++hhyMMMNmmmNhdyddy-                                        
                            .hmhdssmmNyo/ohdyNMMNmmmmhmhmhdo`                                       
                            `yNdyhydhNys/smyhNNMMNNNmmhmmhmds.                                      
                            `smmdshdhNdo+hms/mNNNNMNmmhymdmdd:                                      
                             oyddsdddhh+ymd/ -mNNNNNMmmyydNsh/                                      
                             :yysyydmddymds.  -dmmNNMNmdyyNhho`                                     
                              +ssydhmmmNdy+    .hmmNNNNmdhydhy/                                     
                              :ssdhyomhNshs     .dmmNNNNdmsshhso`                                   
                              +shdo+omhmod/      /mmmNMNmddsshhy`                                   
                              /ydyoyodmh+y.       omNmMNNdddyyhs`                                   
                              ohdsydsdmhod.        +NmNMNNhmdmdh:                                   
                             `smmy+symmsyy`        ommmNNNmhNNhs.                                   
                             +hNhooydNmdh+`       `ddmmNmmNhNmy/                                    
                           `/ymhshmmdhhy+.        omdmNNmNddNms`                                    
                          `oohhyhdhsyhdy.       `+mmmmmNNmhhdhs                                     
                          odohhhmdsshNys`       +hMmNmdmNdmmdh.                                     
                         :dhohhhmdyshmyy`       smNmmhmNmhmmmo                                      
                        `sd++yhdNdysymys`       :mNdhmNNmhhdd`                                      
                        :ym++shmmmysydd+        `hhhNmNmhymd+                                       
                        oyNooydmmdysyhh`         /hmNNNdhddd`                                       
                       `sydssymmmhyssd/          .mNmNMddNd+                                        
                        osmshymdyysso:           -dNNMNddmh`                                        
                        :ydoshmhssyy+            ymNMNmmNms                                         
                        `oyoshNmyyds:           /dNNNmNdmd+                                         
                         +yyhmhNhdh+:           hmmmmmNmhdy.                                        
                         osmNdyNdmhs-          .hmmNNmNmhdmy/                                       
                        :sdmmhydmdys          -ydmmmmmNddmddh/                                      
                        odhddoydNds/         `ydmmhdNmdmNmyydh+`                                    
                       .yhhmyodmMd+/         +dmmdmNNdmNyhhymNdo.                                   
                       :hsNmyydNmd+s       `+mmmdd/mddd/ :mdhmmhy                                   
                       :hhMdyymNdh+o-      `:/ss/``dh/.  `dmh-ydh                                   
                       oddMsshNNNyso.             `/`     :os` ..                                   
                      /hNmmoymMNNdys:                                                               
                     /shMmhshmNdMhsoo+`                                                             
                    .yyhMhhhhdhhNdhssss`                                                            
                    +ydNdshhdhhhmdddysh/                                                            
                   .ssmdosyhmhdy/hdhysyh:                                                           
                   -hhNsyyyNdyhd+-yddhyyys-`                                                        
                 .yddmmyhhmNyshs-//+ymmysy+-                                                        
                 /ssoshhddm/+sh-  ./ `-oyo`                                                         
                     -so+:` `/-    `
*/
