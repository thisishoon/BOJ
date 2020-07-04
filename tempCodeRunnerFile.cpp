for(int d=0; d<2; d++){
        int ny, nx, nd;
        if(d==0){
            nd = (pre+6+1)%6;
            ny = y + dy[nd];
            nx = x + dx[nd];
        }
        else{
            nd = (pre+6-1)%6;
            ny = y + dy[nd];
            nx = x + dx[nd];
        }

        backtrack(ny, nx, nd, cnt+1);
    }