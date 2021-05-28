#include <bits/stdc++.h>

int daysToShip(std::vector<int>& weights, int ship_capacity) {
    int count = 0,
        acc = 0;
    auto first = weights.begin();
    
    while (first != weights.end()) {
        acc += *first;

        /**
         * No caso da variável acc seja maior que a capacidade, a entrega não pode ser formada com o
         * último produto, assim, o produto atual deve iniciar o próximo carregamento na variável acc. 
         */
        if (acc > ship_capacity) {
            count++;
            acc = *first;
        }
        /**
         * No caso da variável acc seja igual, a entrega foi formada, assim, o próximo carregamento começa
         * zerado na variável acc.
         */
        if (acc == ship_capacity) {
            count++;
            acc = 0;
        }

        first++;
    }

    /**
     * Aqui verifica-se faltou formar uma entrega, no caso do loop anterior ter parado sem formar a última
     * entrega ou se a capacidade sobre para levar todos os produtos em apenas um dia. 
    */
    if (acc || !count) {
        count++;
    }

    return count;
}

int shipWithinDaysLinear(std::vector<int>& weights, int days) {
    int avg_weight,
        weightest_product,
        ship_capacity_hint,
        days_res;

    weightest_product  = *std::max_element(weights.begin(), weights.end());
    avg_weight         = ceil((double)std::accumulate(weights.begin(), weights.end(), 0)/days);
    ship_capacity_hint = std::max(avg_weight, weightest_product);
    days_res           = daysToShip(weights, ship_capacity_hint);

    while (days_res > days) {
        days_res = daysToShip(weights, ++ship_capacity_hint);
    }
    
    return ship_capacity_hint;
}

int shipWithinDays(std::vector<int>& weights, int days) {
    int avg_weight,
        total_weight,
        weightest_product,
        beg,
        end,
        mid,
        res,
        days_res;

    total_weight      = std::accumulate(weights.begin(), weights.end(), 0);
    weightest_product = *std::max_element(weights.begin(), weights.end());
    avg_weight        = ceil(((double)total_weight) / (double)days);
    beg               = std::max(avg_weight, weightest_product);
    end               = total_weight;
    res               = total_weight;

    if (daysToShip(weights,beg) >= days) {
        return beg;
    }

    beg += 1;

    while (beg <= end) {
        mid = (end + beg)/2;
        days_res = daysToShip(weights, mid);
        
        if (days_res > days) {
            beg = mid + 1;
        } else {
            end = mid - 1;

            if (mid < res) {
                res = mid;
            }
        }

    }

    return res;
}

int main(int argc, char const *argv[])
{
    std::vector<int> w{1,2,3,1,1}; //3
    int d = 4;   
    std::vector<int> w2{3,2,2,4,1,4}; //6
    int d2 = 3;
    std::vector<int> w3{1,2,3,4,5,6,7,8,9,10}; //15
    int d3 = 5;
    std::vector<int> w4{1,2,3,4,5,6,7,8,9,10}; //55
    int d4 = 1;
    std::vector<int> w5{68,25,170,494,202,88,151,296,329,365,417,81,441,366,230,408,240,356,253,489,137,209};
    int d5 = 11;
    std::vector<int> w6{214,376,385,64,203,394,117,305,297,253,110,470,340,388,482,182,341,43,184,314,265,418,332,111,18,263,4,243};
    int d6 = 14;
    std::vector<int> w7{376,80,176,64,421,250,163,252,490,229,408,179,106,185,108,483,349,206,76,127,112,384,170,125,52,111,457,326,387,140,9,205,462,453,464,464,89,17,362,290,102,278,462,343,69,430,19,476,461,270,180,148,454,422,460,20,150,271,143,491,120,111,291,383,364,101,100,38,9,306,185,326,189,325,372,74,329,240,114,154,6,257,172,355,337,186,87,377,391,453,309,47,234,257,434,338,418,207,176,403,497,201,147,164,92,451,211,135,28,73,25,223,134,418,481,81,191,268,146,452,177,158,8,169,208,149,325,472,141,423,197,241,250,423,139,101,264,94,73,454,160,256,204,354,103,281,425,413,158,93,477,330,183,285,335,370,146,135,440,496,264,97,474,190,307,142,202,95,92,56,152,108,12,109,247,191,8,11,398,279,1,240,129,349,301,482,194,164,424,43,420,355,355,294,203,485,141,124,98,128,333,85,19,39,221,329,155,207,270,191,416,395,61,85,357,400,143,337,445,177,98,150,112,195,319,21,488,407,130,133,398,55,433,307,303,297,381,234,287,257,347,25,237,5,325,112,285,132,318,427,421,448,65,259,304,78,327,490,166,27,256,139,294,361,42,52,95,122,422,442,271,441,133,397,375,186,464,314,453,183,425,431,241,22,80,490,476,232,359,65,288,361,218,480,290,389,243,343,427,404,87,149,208,479,243,312,185,469,421,305,466,335,332,117,265,409,199,47,317,355,267,279,6,429,404,211,167,75,384,360,287,137,453,361,152,283,46,208,195,207,405,412,354,278,464,381,333,487,183,311,226,225,55,451,461,263,143,160,212,451,250,296,155,424,114,296,125,470,284,443,430,494,238,144,176,180,91,500,10,339,379,189,375,388,492,461,267,104,334,167,53,93,500,445,196,89,72,409,395,415,219,157,161,88,71,98,361,31,387,216,182,110,362,437,452,495,409,74,442,3,229,197,191,78,206,69,133,217,278,436,112,11,354,496,88,164,256,103,126,293,292,20,355,458,227,467,170,431,70,404,421,56,144,73,148,105,328,51,134,426,80,18,118,440,194,158,323,366,313,162,500,297,448,217,49,333,499,124,280,230,476,73,337,487,271,499,498,98,331,76,408,338,159,154,104,208,185,250,98,479,171,360,150,112,305,177,454,102,212,43,302,123,418,124,12,133,339,244,380,254,318,107,277,149,58,268,378,98,337,56,130,470,393,459,177,468,142,498,140,490,189,380,20,338,452,330,376,409,279,50,311,219,373,312,383,105,25,268,21,278,13,181,370,191,131,233,123,375,419,403,466,11,438,91,71,455,122,382,468,479,328,135,5,467,448,311,497,400,260,310,427,349,182,152,7,62,133,225,354,40,100,313,289,195,392,249,318,287,457,387,361,136,460,243,236,50,412,440,124,93,376,95,350,430,390,149,203,440,252,32,461,300,426,170,495,217,269,57,257,105,179,380,301,58,325,440,144,102,455,352,455,80,300,370,58,393,239,380,104,364,467,136,296,169,364,224,394,338,39,319,428,81,194,314,370,143,162,472,415,149,315,318,74,258,496,475,377,346,20,14,417,26,362,295,388,493,370,249,13,488,54,195,72,263,194,155,459,250,39,210,455,86,340,6,105,297,196,23,217,333,434,129};
    int d7 = 361;

    std::cout << "sequencial: " << std::endl;
    auto beg = std::chrono::high_resolution_clock::now();
    std::cout << shipWithinDaysLinear(w, d)   << std::endl;
    std::cout << shipWithinDaysLinear(w2, d2) << std::endl;
    std::cout << shipWithinDaysLinear(w3, d3) << std::endl;
    std::cout << shipWithinDaysLinear(w4, d4) << std::endl;
    std::cout << shipWithinDaysLinear(w5, d5) << std::endl;
    std::cout << shipWithinDaysLinear(w6, d6) << std::endl;
    std::cout << shipWithinDaysLinear(w7, d7) << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - beg);
    std::cout << "dur: " << dur.count() << std::endl;

    std::cout << "busca binaria: " << std::endl;
    beg = std::chrono::high_resolution_clock::now();
    std::cout << shipWithinDays(w, d)   << std::endl;
    std::cout << shipWithinDays(w2, d2) << std::endl;
    std::cout << shipWithinDays(w3, d3) << std::endl;
    std::cout << shipWithinDays(w4, d4) << std::endl;
    std::cout << shipWithinDays(w5, d5) << std::endl;
    std::cout << shipWithinDays(w6, d6) << std::endl;
    std::cout << shipWithinDays(w7, d7) << std::endl;
    end = std::chrono::high_resolution_clock::now();
    dur = std::chrono::duration_cast<std::chrono::microseconds>(end - beg);
    std::cout << "dur: " << dur.count() << std::endl;

    return 0;
}