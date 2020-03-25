for(k = 0; k < n; k++){
            for(i = 1; i <= n; i++){
                for(j = i+1; j <= n; j++){
                    if(i!=k){
                        city[i][j] = min(city[i][k]+city[k][j], city[i][j]);
                    }
                }
            }
        }