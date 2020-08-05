#include<stdio.h>
#include<algorithm>

using namespace std;

struct treeNode {
	int data;
	int depth;
	treeNode* parent;

	treeNode() {}

	treeNode(int d) {
		data = d;
		depth = 0;
	}
	treeNode(int d, treeNode* p) {
		data = d;
		parent = p;
		depth = parent->depth + 1;
	}
};

int findCCAncestor(treeNode* node1, treeNode* node2) {
	int depthDifference = node1->depth - node2->depth;

	//Shortcuts
	for (int i = 0; i < depthDifference; i++)
		node1 = node1->parent;
	for (int i = 0; i > depthDifference; i--)
		node2 = node2->parent;

	if (node1->data == node2->data)
		return node1->data;

	if (node1->depth > node2->depth) return findCCAncestor(node1->parent, node2);
	if (node1->depth < node2->depth) return findCCAncestor(node1, node2->parent);
	return findCCAncestor(node1->parent, node2->parent);
}

int findCCAncestorShortCutWrapper(treeNode* node1, treeNode* node2) {
	int depthDifference = node1->depth - node2->depth;

	//Shortcuts
	for (int i = 0; i < depthDifference; i++)
		node1 = node1->parent;
	for (int i = 0; i > depthDifference; i--)
		node2 = node2->parent;

	return findCCAncestor(node1, node2);
}

int main() {
	int T;
	int num, N, parentData;
	int i;

	scanf("%i", &T);
	for (int cases = 0; cases < T; cases++) {
		scanf("%i %i", &num, &N);

		treeNode* myTree[100];
		myTree[num] = new treeNode (num);
		for (i = 0; i < N-1; i++) {
			scanf("%i %i", &num, &parentData);
			myTree[num] = new treeNode(num, myTree[parentData]);
		}
		scanf("%i %i", &num, &N);
		printf("%i\n", findCCAncestorShortCutWrapper(myTree[num], myTree[N]) );
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
                     `:oydhmdNNNNNNMMNMNNNNMNhhdmhhshddyhhdhhmyossys`                               
                       +mmNNdmMmmNMMmNMNNMMMm```-/shydhyhhddsyhhy+y:                                
                       :sosyhNMNdNMMNmNNMNNNy     -yhddhddNMmhyhhhh`                                
                        ``dNNMyssmNmmNNMMNNm`      .yhsshdmdhyo+shy`                                
                          +NMNy:/dmdmNNMMNNh`   ``.-yddsydyyyys+os/                                 
                      `-.  sdmmmdmmmdmNNNNNmhdhhhdmmNmyhhhsyyyo/os.                                 
                       -/s/yhdddddddddmNNNNmmNMMNhhdmhyyyydhyso/y+     ``                           
              ``      ./+hmhdNNNmdhhhmmmmmmdmNNmhdmMdhdsyyhshhyos/  ```-                            
              -o`  `-+ydmhddNMNhhdmddyhhyhdNMMNNNmmhhhNdhdyshhosyho::ooy::-.                        
             `so.-oyhdhhydNddNmhsydhhyyhdmmmNmmmmNmhmhNmdmydhyyyNNNmyhh:.`                          
             +myydmhhddhdmmhhhhdhdmdmdhyyhdhhdddmmmmmmNdmdhmmdmshyhNdyys-                           
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
 ``-oshdddhho:`              /Nmmmmmdmmdmmmmmddddhhddh:              ..-+ymmmmmmmmmmmNNmdhhhs/` `-s-
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