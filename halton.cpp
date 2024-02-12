#include "halton.h"

uint32_t ReverseBits32(uint32_t n) {
    n = (n << 16) | (n >> 16);
    n = ((n & 0x00ff00ff) << 8) | ((n & 0xff00ff00) >> 8);
    n = ((n & 0x0f0f0f0f) << 4) | ((n & 0xf0f0f0f0) >> 4);
    n = ((n & 0x33333333) << 2) | ((n & 0xcccccccc) >> 2);
    n = ((n & 0x55555555) << 1) | ((n & 0xaaaaaaaa) >> 1);
    return n;
}

uint64_t ReverseBits64(uint64_t n) {
    uint64_t n0 = ReverseBits32((uint32_t)n);
    uint64_t n1 = ReverseBits32((uint32_t)(n >> 32));
    return (n0 << 32) | n1;
}

std::vector<uint16_t> ComputeRadicalInversePermutations(RNG &rng) {
    std::vector<uint16_t> perms;
    // Allocate space in _perms_ for radical inverse permutations
    int permArraySize = 0;
    for (int i = 0; i < PrimeTableSize; ++i) permArraySize += Primes[i];
    perms.resize(permArraySize);
    uint16_t *p = &perms[0];
    for (int i = 0; i < PrimeTableSize; ++i) {
        // Generate random permutation for $i$th prime base
        for (int j = 0; j < Primes[i]; ++j) p[j] = j;
        Shuffle(p, Primes[i], 1, rng);
        p += Primes[i];
    }
    return perms;
}

float ScrambledRadicalInverse(int baseIndex, uint64_t a, const uint16_t *perm) {
    switch (baseIndex) {
        case 0:
            return ScrambledRadicalInverseSpecialized<2>(perm, a);
        case 1:
            return ScrambledRadicalInverseSpecialized<3>(perm, a);
        case 2:
            return ScrambledRadicalInverseSpecialized<5>(perm, a);
        case 3:
            return ScrambledRadicalInverseSpecialized<7>(perm, a);
        case 4:
            return ScrambledRadicalInverseSpecialized<11>(perm, a);
        case 5:
            return ScrambledRadicalInverseSpecialized<13>(perm, a);
        case 6:
            return ScrambledRadicalInverseSpecialized<17>(perm, a);
        case 7:
            return ScrambledRadicalInverseSpecialized<19>(perm, a);
        case 8:
            return ScrambledRadicalInverseSpecialized<23>(perm, a);
        case 9:
            return ScrambledRadicalInverseSpecialized<29>(perm, a);
        case 10:
            return ScrambledRadicalInverseSpecialized<31>(perm, a);
        case 11:
            return ScrambledRadicalInverseSpecialized<37>(perm, a);
        case 12:
            return ScrambledRadicalInverseSpecialized<41>(perm, a);
        case 13:
            return ScrambledRadicalInverseSpecialized<43>(perm, a);
        case 14:
            return ScrambledRadicalInverseSpecialized<47>(perm, a);
        case 15:
            return ScrambledRadicalInverseSpecialized<53>(perm, a);
        case 16:
            return ScrambledRadicalInverseSpecialized<59>(perm, a);
        case 17:
            return ScrambledRadicalInverseSpecialized<61>(perm, a);
        case 18:
            return ScrambledRadicalInverseSpecialized<67>(perm, a);
        case 19:
            return ScrambledRadicalInverseSpecialized<71>(perm, a);
        case 20:
            return ScrambledRadicalInverseSpecialized<73>(perm, a);
        case 21:
            return ScrambledRadicalInverseSpecialized<79>(perm, a);
        case 22:
            return ScrambledRadicalInverseSpecialized<83>(perm, a);
        case 23:
            return ScrambledRadicalInverseSpecialized<89>(perm, a);
        case 24:
            return ScrambledRadicalInverseSpecialized<97>(perm, a);
        case 25:
            return ScrambledRadicalInverseSpecialized<101>(perm, a);
        case 26:
            return ScrambledRadicalInverseSpecialized<103>(perm, a);
        case 27:
            return ScrambledRadicalInverseSpecialized<107>(perm, a);
        case 28:
            return ScrambledRadicalInverseSpecialized<109>(perm, a);
        case 29:
            return ScrambledRadicalInverseSpecialized<113>(perm, a);
        case 30:
            return ScrambledRadicalInverseSpecialized<127>(perm, a);
        case 31:
            return ScrambledRadicalInverseSpecialized<131>(perm, a);
        case 32:
            return ScrambledRadicalInverseSpecialized<137>(perm, a);
        case 33:
            return ScrambledRadicalInverseSpecialized<139>(perm, a);
        case 34:
            return ScrambledRadicalInverseSpecialized<149>(perm, a);
        case 35:
            return ScrambledRadicalInverseSpecialized<151>(perm, a);
        case 36:
            return ScrambledRadicalInverseSpecialized<157>(perm, a);
        case 37:
            return ScrambledRadicalInverseSpecialized<163>(perm, a);
        case 38:
            return ScrambledRadicalInverseSpecialized<167>(perm, a);
        case 39:
            return ScrambledRadicalInverseSpecialized<173>(perm, a);
        case 40:
            return ScrambledRadicalInverseSpecialized<179>(perm, a);
        case 41:
            return ScrambledRadicalInverseSpecialized<181>(perm, a);
        case 42:
            return ScrambledRadicalInverseSpecialized<191>(perm, a);
        case 43:
            return ScrambledRadicalInverseSpecialized<193>(perm, a);
        case 44:
            return ScrambledRadicalInverseSpecialized<197>(perm, a);
        case 45:
            return ScrambledRadicalInverseSpecialized<199>(perm, a);
        case 46:
            return ScrambledRadicalInverseSpecialized<211>(perm, a);
        case 47:
            return ScrambledRadicalInverseSpecialized<223>(perm, a);
        case 48:
            return ScrambledRadicalInverseSpecialized<227>(perm, a);
        case 49:
            return ScrambledRadicalInverseSpecialized<229>(perm, a);
        case 50:
            return ScrambledRadicalInverseSpecialized<233>(perm, a);
        case 51:
            return ScrambledRadicalInverseSpecialized<239>(perm, a);
        case 52:
            return ScrambledRadicalInverseSpecialized<241>(perm, a);
        case 53:
            return ScrambledRadicalInverseSpecialized<251>(perm, a);
        case 54:
            return ScrambledRadicalInverseSpecialized<257>(perm, a);
        case 55:
            return ScrambledRadicalInverseSpecialized<263>(perm, a);
        case 56:
            return ScrambledRadicalInverseSpecialized<269>(perm, a);
        case 57:
            return ScrambledRadicalInverseSpecialized<271>(perm, a);
        case 58:
            return ScrambledRadicalInverseSpecialized<277>(perm, a);
        case 59:
            return ScrambledRadicalInverseSpecialized<281>(perm, a);
        case 60:
            return ScrambledRadicalInverseSpecialized<283>(perm, a);
        case 61:
            return ScrambledRadicalInverseSpecialized<293>(perm, a);
        case 62:
            return ScrambledRadicalInverseSpecialized<307>(perm, a);
        case 63:
            return ScrambledRadicalInverseSpecialized<311>(perm, a);
        case 64:
            return ScrambledRadicalInverseSpecialized<313>(perm, a);
        case 65:
            return ScrambledRadicalInverseSpecialized<317>(perm, a);
        case 66:
            return ScrambledRadicalInverseSpecialized<331>(perm, a);
        case 67:
            return ScrambledRadicalInverseSpecialized<337>(perm, a);
        case 68:
            return ScrambledRadicalInverseSpecialized<347>(perm, a);
        case 69:
            return ScrambledRadicalInverseSpecialized<349>(perm, a);
        case 70:
            return ScrambledRadicalInverseSpecialized<353>(perm, a);
        case 71:
            return ScrambledRadicalInverseSpecialized<359>(perm, a);
        case 72:
            return ScrambledRadicalInverseSpecialized<367>(perm, a);
        case 73:
            return ScrambledRadicalInverseSpecialized<373>(perm, a);
        case 74:
            return ScrambledRadicalInverseSpecialized<379>(perm, a);
        case 75:
            return ScrambledRadicalInverseSpecialized<383>(perm, a);
        case 76:
            return ScrambledRadicalInverseSpecialized<389>(perm, a);
        case 77:
            return ScrambledRadicalInverseSpecialized<397>(perm, a);
        case 78:
            return ScrambledRadicalInverseSpecialized<401>(perm, a);
        case 79:
            return ScrambledRadicalInverseSpecialized<409>(perm, a);
        case 80:
            return ScrambledRadicalInverseSpecialized<419>(perm, a);
        case 81:
            return ScrambledRadicalInverseSpecialized<421>(perm, a);
        case 82:
            return ScrambledRadicalInverseSpecialized<431>(perm, a);
        case 83:
            return ScrambledRadicalInverseSpecialized<433>(perm, a);
        case 84:
            return ScrambledRadicalInverseSpecialized<439>(perm, a);
        case 85:
            return ScrambledRadicalInverseSpecialized<443>(perm, a);
        case 86:
            return ScrambledRadicalInverseSpecialized<449>(perm, a);
        case 87:
            return ScrambledRadicalInverseSpecialized<457>(perm, a);
        case 88:
            return ScrambledRadicalInverseSpecialized<461>(perm, a);
        case 89:
            return ScrambledRadicalInverseSpecialized<463>(perm, a);
        case 90:
            return ScrambledRadicalInverseSpecialized<467>(perm, a);
        case 91:
            return ScrambledRadicalInverseSpecialized<479>(perm, a);
        case 92:
            return ScrambledRadicalInverseSpecialized<487>(perm, a);
        case 93:
            return ScrambledRadicalInverseSpecialized<491>(perm, a);
        case 94:
            return ScrambledRadicalInverseSpecialized<499>(perm, a);
        case 95:
            return ScrambledRadicalInverseSpecialized<503>(perm, a);
        case 96:
            return ScrambledRadicalInverseSpecialized<509>(perm, a);
        case 97:
            return ScrambledRadicalInverseSpecialized<521>(perm, a);
        case 98:
            return ScrambledRadicalInverseSpecialized<523>(perm, a);
        case 99:
            return ScrambledRadicalInverseSpecialized<541>(perm, a);
        case 100:
            return ScrambledRadicalInverseSpecialized<547>(perm, a);
        case 101:
            return ScrambledRadicalInverseSpecialized<557>(perm, a);
        case 102:
            return ScrambledRadicalInverseSpecialized<563>(perm, a);
        case 103:
            return ScrambledRadicalInverseSpecialized<569>(perm, a);
        case 104:
            return ScrambledRadicalInverseSpecialized<571>(perm, a);
        case 105:
            return ScrambledRadicalInverseSpecialized<577>(perm, a);
        case 106:
            return ScrambledRadicalInverseSpecialized<587>(perm, a);
        case 107:
            return ScrambledRadicalInverseSpecialized<593>(perm, a);
        case 108:
            return ScrambledRadicalInverseSpecialized<599>(perm, a);
        case 109:
            return ScrambledRadicalInverseSpecialized<601>(perm, a);
        case 110:
            return ScrambledRadicalInverseSpecialized<607>(perm, a);
        case 111:
            return ScrambledRadicalInverseSpecialized<613>(perm, a);
        case 112:
            return ScrambledRadicalInverseSpecialized<617>(perm, a);
        case 113:
            return ScrambledRadicalInverseSpecialized<619>(perm, a);
        case 114:
            return ScrambledRadicalInverseSpecialized<631>(perm, a);
        case 115:
            return ScrambledRadicalInverseSpecialized<641>(perm, a);
        case 116:
            return ScrambledRadicalInverseSpecialized<643>(perm, a);
        case 117:
            return ScrambledRadicalInverseSpecialized<647>(perm, a);
        case 118:
            return ScrambledRadicalInverseSpecialized<653>(perm, a);
        case 119:
            return ScrambledRadicalInverseSpecialized<659>(perm, a);
        case 120:
            return ScrambledRadicalInverseSpecialized<661>(perm, a);
        case 121:
            return ScrambledRadicalInverseSpecialized<673>(perm, a);
        case 122:
            return ScrambledRadicalInverseSpecialized<677>(perm, a);
        case 123:
            return ScrambledRadicalInverseSpecialized<683>(perm, a);
        case 124:
            return ScrambledRadicalInverseSpecialized<691>(perm, a);
        case 125:
            return ScrambledRadicalInverseSpecialized<701>(perm, a);
        case 126:
            return ScrambledRadicalInverseSpecialized<709>(perm, a);
        case 127:
            return ScrambledRadicalInverseSpecialized<719>(perm, a);
        case 128:
            return ScrambledRadicalInverseSpecialized<727>(perm, a);
        case 129:
            return ScrambledRadicalInverseSpecialized<733>(perm, a);
        case 130:
            return ScrambledRadicalInverseSpecialized<739>(perm, a);
        case 131:
            return ScrambledRadicalInverseSpecialized<743>(perm, a);
        case 132:
            return ScrambledRadicalInverseSpecialized<751>(perm, a);
        case 133:
            return ScrambledRadicalInverseSpecialized<757>(perm, a);
        case 134:
            return ScrambledRadicalInverseSpecialized<761>(perm, a);
        case 135:
            return ScrambledRadicalInverseSpecialized<769>(perm, a);
        case 136:
            return ScrambledRadicalInverseSpecialized<773>(perm, a);
        case 137:
            return ScrambledRadicalInverseSpecialized<787>(perm, a);
        case 138:
            return ScrambledRadicalInverseSpecialized<797>(perm, a);
        case 139:
            return ScrambledRadicalInverseSpecialized<809>(perm, a);
        case 140:
            return ScrambledRadicalInverseSpecialized<811>(perm, a);
        case 141:
            return ScrambledRadicalInverseSpecialized<821>(perm, a);
        case 142:
            return ScrambledRadicalInverseSpecialized<823>(perm, a);
        case 143:
            return ScrambledRadicalInverseSpecialized<827>(perm, a);
        case 144:
            return ScrambledRadicalInverseSpecialized<829>(perm, a);
        case 145:
            return ScrambledRadicalInverseSpecialized<839>(perm, a);
        case 146:
            return ScrambledRadicalInverseSpecialized<853>(perm, a);
        case 147:
            return ScrambledRadicalInverseSpecialized<857>(perm, a);
        case 148:
            return ScrambledRadicalInverseSpecialized<859>(perm, a);
        case 149:
            return ScrambledRadicalInverseSpecialized<863>(perm, a);
        case 150:
            return ScrambledRadicalInverseSpecialized<877>(perm, a);
        case 151:
            return ScrambledRadicalInverseSpecialized<881>(perm, a);
        case 152:
            return ScrambledRadicalInverseSpecialized<883>(perm, a);
        case 153:
            return ScrambledRadicalInverseSpecialized<887>(perm, a);
        case 154:
            return ScrambledRadicalInverseSpecialized<907>(perm, a);
        case 155:
            return ScrambledRadicalInverseSpecialized<911>(perm, a);
        case 156:
            return ScrambledRadicalInverseSpecialized<919>(perm, a);
        case 157:
            return ScrambledRadicalInverseSpecialized<929>(perm, a);
        case 158:
            return ScrambledRadicalInverseSpecialized<937>(perm, a);
        case 159:
            return ScrambledRadicalInverseSpecialized<941>(perm, a);
        case 160:
            return ScrambledRadicalInverseSpecialized<947>(perm, a);
        case 161:
            return ScrambledRadicalInverseSpecialized<953>(perm, a);
        case 162:
            return ScrambledRadicalInverseSpecialized<967>(perm, a);
        case 163:
            return ScrambledRadicalInverseSpecialized<971>(perm, a);
        case 164:
            return ScrambledRadicalInverseSpecialized<977>(perm, a);
        case 165:
            return ScrambledRadicalInverseSpecialized<983>(perm, a);
        case 166:
            return ScrambledRadicalInverseSpecialized<991>(perm, a);
        case 167:
            return ScrambledRadicalInverseSpecialized<997>(perm, a);
        case 168:
            return ScrambledRadicalInverseSpecialized<1009>(perm, a);
        case 169:
            return ScrambledRadicalInverseSpecialized<1013>(perm, a);
        case 170:
            return ScrambledRadicalInverseSpecialized<1019>(perm, a);
        case 171:
            return ScrambledRadicalInverseSpecialized<1021>(perm, a);
        case 172:
            return ScrambledRadicalInverseSpecialized<1031>(perm, a);
        case 173:
            return ScrambledRadicalInverseSpecialized<1033>(perm, a);
        case 174:
            return ScrambledRadicalInverseSpecialized<1039>(perm, a);
        case 175:
            return ScrambledRadicalInverseSpecialized<1049>(perm, a);
        case 176:
            return ScrambledRadicalInverseSpecialized<1051>(perm, a);
        case 177:
            return ScrambledRadicalInverseSpecialized<1061>(perm, a);
        case 178:
            return ScrambledRadicalInverseSpecialized<1063>(perm, a);
        case 179:
            return ScrambledRadicalInverseSpecialized<1069>(perm, a);
        case 180:
            return ScrambledRadicalInverseSpecialized<1087>(perm, a);
        case 181:
            return ScrambledRadicalInverseSpecialized<1091>(perm, a);
        case 182:
            return ScrambledRadicalInverseSpecialized<1093>(perm, a);
        case 183:
            return ScrambledRadicalInverseSpecialized<1097>(perm, a);
        case 184:
            return ScrambledRadicalInverseSpecialized<1103>(perm, a);
        case 185:
            return ScrambledRadicalInverseSpecialized<1109>(perm, a);
        case 186:
            return ScrambledRadicalInverseSpecialized<1117>(perm, a);
        case 187:
            return ScrambledRadicalInverseSpecialized<1123>(perm, a);
        case 188:
            return ScrambledRadicalInverseSpecialized<1129>(perm, a);
        case 189:
            return ScrambledRadicalInverseSpecialized<1151>(perm, a);
        case 190:
            return ScrambledRadicalInverseSpecialized<1153>(perm, a);
        case 191:
            return ScrambledRadicalInverseSpecialized<1163>(perm, a);
        case 192:
            return ScrambledRadicalInverseSpecialized<1171>(perm, a);
        case 193:
            return ScrambledRadicalInverseSpecialized<1181>(perm, a);
        case 194:
            return ScrambledRadicalInverseSpecialized<1187>(perm, a);
        case 195:
            return ScrambledRadicalInverseSpecialized<1193>(perm, a);
        case 196:
            return ScrambledRadicalInverseSpecialized<1201>(perm, a);
        case 197:
            return ScrambledRadicalInverseSpecialized<1213>(perm, a);
        case 198:
            return ScrambledRadicalInverseSpecialized<1217>(perm, a);
        case 199:
            return ScrambledRadicalInverseSpecialized<1223>(perm, a);
        case 200:
            return ScrambledRadicalInverseSpecialized<1229>(perm, a);
        case 201:
            return ScrambledRadicalInverseSpecialized<1231>(perm, a);
        case 202:
            return ScrambledRadicalInverseSpecialized<1237>(perm, a);
        case 203:
            return ScrambledRadicalInverseSpecialized<1249>(perm, a);
        case 204:
            return ScrambledRadicalInverseSpecialized<1259>(perm, a);
        case 205:
            return ScrambledRadicalInverseSpecialized<1277>(perm, a);
        case 206:
            return ScrambledRadicalInverseSpecialized<1279>(perm, a);
        case 207:
            return ScrambledRadicalInverseSpecialized<1283>(perm, a);
        case 208:
            return ScrambledRadicalInverseSpecialized<1289>(perm, a);
        case 209:
            return ScrambledRadicalInverseSpecialized<1291>(perm, a);
        case 210:
            return ScrambledRadicalInverseSpecialized<1297>(perm, a);
        case 211:
            return ScrambledRadicalInverseSpecialized<1301>(perm, a);
        case 212:
            return ScrambledRadicalInverseSpecialized<1303>(perm, a);
        case 213:
            return ScrambledRadicalInverseSpecialized<1307>(perm, a);
        case 214:
            return ScrambledRadicalInverseSpecialized<1319>(perm, a);
        case 215:
            return ScrambledRadicalInverseSpecialized<1321>(perm, a);
        case 216:
            return ScrambledRadicalInverseSpecialized<1327>(perm, a);
        case 217:
            return ScrambledRadicalInverseSpecialized<1361>(perm, a);
        case 218:
            return ScrambledRadicalInverseSpecialized<1367>(perm, a);
        case 219:
            return ScrambledRadicalInverseSpecialized<1373>(perm, a);
        case 220:
            return ScrambledRadicalInverseSpecialized<1381>(perm, a);
        case 221:
            return ScrambledRadicalInverseSpecialized<1399>(perm, a);
        case 222:
            return ScrambledRadicalInverseSpecialized<1409>(perm, a);
        case 223:
            return ScrambledRadicalInverseSpecialized<1423>(perm, a);
        case 224:
            return ScrambledRadicalInverseSpecialized<1427>(perm, a);
        case 225:
            return ScrambledRadicalInverseSpecialized<1429>(perm, a);
        case 226:
            return ScrambledRadicalInverseSpecialized<1433>(perm, a);
        case 227:
            return ScrambledRadicalInverseSpecialized<1439>(perm, a);
        case 228:
            return ScrambledRadicalInverseSpecialized<1447>(perm, a);
        case 229:
            return ScrambledRadicalInverseSpecialized<1451>(perm, a);
        case 230:
            return ScrambledRadicalInverseSpecialized<1453>(perm, a);
        case 231:
            return ScrambledRadicalInverseSpecialized<1459>(perm, a);
        case 232:
            return ScrambledRadicalInverseSpecialized<1471>(perm, a);
        case 233:
            return ScrambledRadicalInverseSpecialized<1481>(perm, a);
        case 234:
            return ScrambledRadicalInverseSpecialized<1483>(perm, a);
        case 235:
            return ScrambledRadicalInverseSpecialized<1487>(perm, a);
        case 236:
            return ScrambledRadicalInverseSpecialized<1489>(perm, a);
        case 237:
            return ScrambledRadicalInverseSpecialized<1493>(perm, a);
        case 238:
            return ScrambledRadicalInverseSpecialized<1499>(perm, a);
        case 239:
            return ScrambledRadicalInverseSpecialized<1511>(perm, a);
        case 240:
            return ScrambledRadicalInverseSpecialized<1523>(perm, a);
        case 241:
            return ScrambledRadicalInverseSpecialized<1531>(perm, a);
        case 242:
            return ScrambledRadicalInverseSpecialized<1543>(perm, a);
        case 243:
            return ScrambledRadicalInverseSpecialized<1549>(perm, a);
        case 244:
            return ScrambledRadicalInverseSpecialized<1553>(perm, a);
        case 245:
            return ScrambledRadicalInverseSpecialized<1559>(perm, a);
        case 246:
            return ScrambledRadicalInverseSpecialized<1567>(perm, a);
        case 247:
            return ScrambledRadicalInverseSpecialized<1571>(perm, a);
        case 248:
            return ScrambledRadicalInverseSpecialized<1579>(perm, a);
        case 249:
            return ScrambledRadicalInverseSpecialized<1583>(perm, a);
        case 250:
            return ScrambledRadicalInverseSpecialized<1597>(perm, a);
        case 251:
            return ScrambledRadicalInverseSpecialized<1601>(perm, a);
        case 252:
            return ScrambledRadicalInverseSpecialized<1607>(perm, a);
        case 253:
            return ScrambledRadicalInverseSpecialized<1609>(perm, a);
        case 254:
            return ScrambledRadicalInverseSpecialized<1613>(perm, a);
        case 255:
            return ScrambledRadicalInverseSpecialized<1619>(perm, a);
        case 256:
            return ScrambledRadicalInverseSpecialized<1621>(perm, a);
        case 257:
            return ScrambledRadicalInverseSpecialized<1627>(perm, a);
        case 258:
            return ScrambledRadicalInverseSpecialized<1637>(perm, a);
        case 259:
            return ScrambledRadicalInverseSpecialized<1657>(perm, a);
        case 260:
            return ScrambledRadicalInverseSpecialized<1663>(perm, a);
        case 261:
            return ScrambledRadicalInverseSpecialized<1667>(perm, a);
        case 262:
            return ScrambledRadicalInverseSpecialized<1669>(perm, a);
        case 263:
            return ScrambledRadicalInverseSpecialized<1693>(perm, a);
        case 264:
            return ScrambledRadicalInverseSpecialized<1697>(perm, a);
        case 265:
            return ScrambledRadicalInverseSpecialized<1699>(perm, a);
        case 266:
            return ScrambledRadicalInverseSpecialized<1709>(perm, a);
        case 267:
            return ScrambledRadicalInverseSpecialized<1721>(perm, a);
        case 268:
            return ScrambledRadicalInverseSpecialized<1723>(perm, a);
        case 269:
            return ScrambledRadicalInverseSpecialized<1733>(perm, a);
        case 270:
            return ScrambledRadicalInverseSpecialized<1741>(perm, a);
        case 271:
            return ScrambledRadicalInverseSpecialized<1747>(perm, a);
        case 272:
            return ScrambledRadicalInverseSpecialized<1753>(perm, a);
        case 273:
            return ScrambledRadicalInverseSpecialized<1759>(perm, a);
        case 274:
            return ScrambledRadicalInverseSpecialized<1777>(perm, a);
        case 275:
            return ScrambledRadicalInverseSpecialized<1783>(perm, a);
        case 276:
            return ScrambledRadicalInverseSpecialized<1787>(perm, a);
        case 277:
            return ScrambledRadicalInverseSpecialized<1789>(perm, a);
        case 278:
            return ScrambledRadicalInverseSpecialized<1801>(perm, a);
        case 279:
            return ScrambledRadicalInverseSpecialized<1811>(perm, a);
        case 280:
            return ScrambledRadicalInverseSpecialized<1823>(perm, a);
        case 281:
            return ScrambledRadicalInverseSpecialized<1831>(perm, a);
        case 282:
            return ScrambledRadicalInverseSpecialized<1847>(perm, a);
        case 283:
            return ScrambledRadicalInverseSpecialized<1861>(perm, a);
        case 284:
            return ScrambledRadicalInverseSpecialized<1867>(perm, a);
        case 285:
            return ScrambledRadicalInverseSpecialized<1871>(perm, a);
        case 286:
            return ScrambledRadicalInverseSpecialized<1873>(perm, a);
        case 287:
            return ScrambledRadicalInverseSpecialized<1877>(perm, a);
        case 288:
            return ScrambledRadicalInverseSpecialized<1879>(perm, a);
        case 289:
            return ScrambledRadicalInverseSpecialized<1889>(perm, a);
        case 290:
            return ScrambledRadicalInverseSpecialized<1901>(perm, a);
        case 291:
            return ScrambledRadicalInverseSpecialized<1907>(perm, a);
        case 292:
            return ScrambledRadicalInverseSpecialized<1913>(perm, a);
        case 293:
            return ScrambledRadicalInverseSpecialized<1931>(perm, a);
        case 294:
            return ScrambledRadicalInverseSpecialized<1933>(perm, a);
        case 295:
            return ScrambledRadicalInverseSpecialized<1949>(perm, a);
        case 296:
            return ScrambledRadicalInverseSpecialized<1951>(perm, a);
        case 297:
            return ScrambledRadicalInverseSpecialized<1973>(perm, a);
        case 298:
            return ScrambledRadicalInverseSpecialized<1979>(perm, a);
        case 299:
            return ScrambledRadicalInverseSpecialized<1987>(perm, a);
        case 300:
            return ScrambledRadicalInverseSpecialized<1993>(perm, a);
        case 301:
            return ScrambledRadicalInverseSpecialized<1997>(perm, a);
        case 302:
            return ScrambledRadicalInverseSpecialized<1999>(perm, a);
        case 303:
            return ScrambledRadicalInverseSpecialized<2003>(perm, a);
        case 304:
            return ScrambledRadicalInverseSpecialized<2011>(perm, a);
        case 305:
            return ScrambledRadicalInverseSpecialized<2017>(perm, a);
        case 306:
            return ScrambledRadicalInverseSpecialized<2027>(perm, a);
        case 307:
            return ScrambledRadicalInverseSpecialized<2029>(perm, a);
        case 308:
            return ScrambledRadicalInverseSpecialized<2039>(perm, a);
        case 309:
            return ScrambledRadicalInverseSpecialized<2053>(perm, a);
        case 310:
            return ScrambledRadicalInverseSpecialized<2063>(perm, a);
        case 311:
            return ScrambledRadicalInverseSpecialized<2069>(perm, a);
        case 312:
            return ScrambledRadicalInverseSpecialized<2081>(perm, a);
        case 313:
            return ScrambledRadicalInverseSpecialized<2083>(perm, a);
        case 314:
            return ScrambledRadicalInverseSpecialized<2087>(perm, a);
        case 315:
            return ScrambledRadicalInverseSpecialized<2089>(perm, a);
        case 316:
            return ScrambledRadicalInverseSpecialized<2099>(perm, a);
        case 317:
            return ScrambledRadicalInverseSpecialized<2111>(perm, a);
        case 318:
            return ScrambledRadicalInverseSpecialized<2113>(perm, a);
        case 319:
            return ScrambledRadicalInverseSpecialized<2129>(perm, a);
        case 320:
            return ScrambledRadicalInverseSpecialized<2131>(perm, a);
        case 321:
            return ScrambledRadicalInverseSpecialized<2137>(perm, a);
        case 322:
            return ScrambledRadicalInverseSpecialized<2141>(perm, a);
        case 323:
            return ScrambledRadicalInverseSpecialized<2143>(perm, a);
        case 324:
            return ScrambledRadicalInverseSpecialized<2153>(perm, a);
        case 325:
            return ScrambledRadicalInverseSpecialized<2161>(perm, a);
        case 326:
            return ScrambledRadicalInverseSpecialized<2179>(perm, a);
        case 327:
            return ScrambledRadicalInverseSpecialized<2203>(perm, a);
        case 328:
            return ScrambledRadicalInverseSpecialized<2207>(perm, a);
        case 329:
            return ScrambledRadicalInverseSpecialized<2213>(perm, a);
        case 330:
            return ScrambledRadicalInverseSpecialized<2221>(perm, a);
        case 331:
            return ScrambledRadicalInverseSpecialized<2237>(perm, a);
        case 332:
            return ScrambledRadicalInverseSpecialized<2239>(perm, a);
        case 333:
            return ScrambledRadicalInverseSpecialized<2243>(perm, a);
        case 334:
            return ScrambledRadicalInverseSpecialized<2251>(perm, a);
        case 335:
            return ScrambledRadicalInverseSpecialized<2267>(perm, a);
        case 336:
            return ScrambledRadicalInverseSpecialized<2269>(perm, a);
        case 337:
            return ScrambledRadicalInverseSpecialized<2273>(perm, a);
        case 338:
            return ScrambledRadicalInverseSpecialized<2281>(perm, a);
        case 339:
            return ScrambledRadicalInverseSpecialized<2287>(perm, a);
        case 340:
            return ScrambledRadicalInverseSpecialized<2293>(perm, a);
        case 341:
            return ScrambledRadicalInverseSpecialized<2297>(perm, a);
        case 342:
            return ScrambledRadicalInverseSpecialized<2309>(perm, a);
        case 343:
            return ScrambledRadicalInverseSpecialized<2311>(perm, a);
        case 344:
            return ScrambledRadicalInverseSpecialized<2333>(perm, a);
        case 345:
            return ScrambledRadicalInverseSpecialized<2339>(perm, a);
        case 346:
            return ScrambledRadicalInverseSpecialized<2341>(perm, a);
        case 347:
            return ScrambledRadicalInverseSpecialized<2347>(perm, a);
        case 348:
            return ScrambledRadicalInverseSpecialized<2351>(perm, a);
        case 349:
            return ScrambledRadicalInverseSpecialized<2357>(perm, a);
        case 350:
            return ScrambledRadicalInverseSpecialized<2371>(perm, a);
        case 351:
            return ScrambledRadicalInverseSpecialized<2377>(perm, a);
        case 352:
            return ScrambledRadicalInverseSpecialized<2381>(perm, a);
        case 353:
            return ScrambledRadicalInverseSpecialized<2383>(perm, a);
        case 354:
            return ScrambledRadicalInverseSpecialized<2389>(perm, a);
        case 355:
            return ScrambledRadicalInverseSpecialized<2393>(perm, a);
        case 356:
            return ScrambledRadicalInverseSpecialized<2399>(perm, a);
        case 357:
            return ScrambledRadicalInverseSpecialized<2411>(perm, a);
        case 358:
            return ScrambledRadicalInverseSpecialized<2417>(perm, a);
        case 359:
            return ScrambledRadicalInverseSpecialized<2423>(perm, a);
        case 360:
            return ScrambledRadicalInverseSpecialized<2437>(perm, a);
        case 361:
            return ScrambledRadicalInverseSpecialized<2441>(perm, a);
        case 362:
            return ScrambledRadicalInverseSpecialized<2447>(perm, a);
        case 363:
            return ScrambledRadicalInverseSpecialized<2459>(perm, a);
        case 364:
            return ScrambledRadicalInverseSpecialized<2467>(perm, a);
        case 365:
            return ScrambledRadicalInverseSpecialized<2473>(perm, a);
        case 366:
            return ScrambledRadicalInverseSpecialized<2477>(perm, a);
        case 367:
            return ScrambledRadicalInverseSpecialized<2503>(perm, a);
        case 368:
            return ScrambledRadicalInverseSpecialized<2521>(perm, a);
        case 369:
            return ScrambledRadicalInverseSpecialized<2531>(perm, a);
        case 370:
            return ScrambledRadicalInverseSpecialized<2539>(perm, a);
        case 371:
            return ScrambledRadicalInverseSpecialized<2543>(perm, a);
        case 372:
            return ScrambledRadicalInverseSpecialized<2549>(perm, a);
        case 373:
            return ScrambledRadicalInverseSpecialized<2551>(perm, a);
        case 374:
            return ScrambledRadicalInverseSpecialized<2557>(perm, a);
        case 375:
            return ScrambledRadicalInverseSpecialized<2579>(perm, a);
        case 376:
            return ScrambledRadicalInverseSpecialized<2591>(perm, a);
        case 377:
            return ScrambledRadicalInverseSpecialized<2593>(perm, a);
        case 378:
            return ScrambledRadicalInverseSpecialized<2609>(perm, a);
        case 379:
            return ScrambledRadicalInverseSpecialized<2617>(perm, a);
        case 380:
            return ScrambledRadicalInverseSpecialized<2621>(perm, a);
        case 381:
            return ScrambledRadicalInverseSpecialized<2633>(perm, a);
        case 382:
            return ScrambledRadicalInverseSpecialized<2647>(perm, a);
        case 383:
            return ScrambledRadicalInverseSpecialized<2657>(perm, a);
        case 384:
            return ScrambledRadicalInverseSpecialized<2659>(perm, a);
        case 385:
            return ScrambledRadicalInverseSpecialized<2663>(perm, a);
        case 386:
            return ScrambledRadicalInverseSpecialized<2671>(perm, a);
        case 387:
            return ScrambledRadicalInverseSpecialized<2677>(perm, a);
        case 388:
            return ScrambledRadicalInverseSpecialized<2683>(perm, a);
        case 389:
            return ScrambledRadicalInverseSpecialized<2687>(perm, a);
        case 390:
            return ScrambledRadicalInverseSpecialized<2689>(perm, a);
        case 391:
            return ScrambledRadicalInverseSpecialized<2693>(perm, a);
        case 392:
            return ScrambledRadicalInverseSpecialized<2699>(perm, a);
        case 393:
            return ScrambledRadicalInverseSpecialized<2707>(perm, a);
        case 394:
            return ScrambledRadicalInverseSpecialized<2711>(perm, a);
        case 395:
            return ScrambledRadicalInverseSpecialized<2713>(perm, a);
        case 396:
            return ScrambledRadicalInverseSpecialized<2719>(perm, a);
        case 397:
            return ScrambledRadicalInverseSpecialized<2729>(perm, a);
        case 398:
            return ScrambledRadicalInverseSpecialized<2731>(perm, a);
        case 399:
            return ScrambledRadicalInverseSpecialized<2741>(perm, a);
        case 400:
            return ScrambledRadicalInverseSpecialized<2749>(perm, a);
        case 401:
            return ScrambledRadicalInverseSpecialized<2753>(perm, a);
        case 402:
            return ScrambledRadicalInverseSpecialized<2767>(perm, a);
        case 403:
            return ScrambledRadicalInverseSpecialized<2777>(perm, a);
        case 404:
            return ScrambledRadicalInverseSpecialized<2789>(perm, a);
        case 405:
            return ScrambledRadicalInverseSpecialized<2791>(perm, a);
        case 406:
            return ScrambledRadicalInverseSpecialized<2797>(perm, a);
        case 407:
            return ScrambledRadicalInverseSpecialized<2801>(perm, a);
        case 408:
            return ScrambledRadicalInverseSpecialized<2803>(perm, a);
        case 409:
            return ScrambledRadicalInverseSpecialized<2819>(perm, a);
        case 410:
            return ScrambledRadicalInverseSpecialized<2833>(perm, a);
        case 411:
            return ScrambledRadicalInverseSpecialized<2837>(perm, a);
        case 412:
            return ScrambledRadicalInverseSpecialized<2843>(perm, a);
        case 413:
            return ScrambledRadicalInverseSpecialized<2851>(perm, a);
        case 414:
            return ScrambledRadicalInverseSpecialized<2857>(perm, a);
        case 415:
            return ScrambledRadicalInverseSpecialized<2861>(perm, a);
        case 416:
            return ScrambledRadicalInverseSpecialized<2879>(perm, a);
        case 417:
            return ScrambledRadicalInverseSpecialized<2887>(perm, a);
        case 418:
            return ScrambledRadicalInverseSpecialized<2897>(perm, a);
        case 419:
            return ScrambledRadicalInverseSpecialized<2903>(perm, a);
        case 420:
            return ScrambledRadicalInverseSpecialized<2909>(perm, a);
        case 421:
            return ScrambledRadicalInverseSpecialized<2917>(perm, a);
        case 422:
            return ScrambledRadicalInverseSpecialized<2927>(perm, a);
        case 423:
            return ScrambledRadicalInverseSpecialized<2939>(perm, a);
        case 424:
            return ScrambledRadicalInverseSpecialized<2953>(perm, a);
        case 425:
            return ScrambledRadicalInverseSpecialized<2957>(perm, a);
        case 426:
            return ScrambledRadicalInverseSpecialized<2963>(perm, a);
        case 427:
            return ScrambledRadicalInverseSpecialized<2969>(perm, a);
        case 428:
            return ScrambledRadicalInverseSpecialized<2971>(perm, a);
        case 429:
            return ScrambledRadicalInverseSpecialized<2999>(perm, a);
        case 430:
            return ScrambledRadicalInverseSpecialized<3001>(perm, a);
        case 431:
            return ScrambledRadicalInverseSpecialized<3011>(perm, a);
        case 432:
            return ScrambledRadicalInverseSpecialized<3019>(perm, a);
        case 433:
            return ScrambledRadicalInverseSpecialized<3023>(perm, a);
        case 434:
            return ScrambledRadicalInverseSpecialized<3037>(perm, a);
        case 435:
            return ScrambledRadicalInverseSpecialized<3041>(perm, a);
        case 436:
            return ScrambledRadicalInverseSpecialized<3049>(perm, a);
        case 437:
            return ScrambledRadicalInverseSpecialized<3061>(perm, a);
        case 438:
            return ScrambledRadicalInverseSpecialized<3067>(perm, a);
        case 439:
            return ScrambledRadicalInverseSpecialized<3079>(perm, a);
        case 440:
            return ScrambledRadicalInverseSpecialized<3083>(perm, a);
        case 441:
            return ScrambledRadicalInverseSpecialized<3089>(perm, a);
        case 442:
            return ScrambledRadicalInverseSpecialized<3109>(perm, a);
        case 443:
            return ScrambledRadicalInverseSpecialized<3119>(perm, a);
        case 444:
            return ScrambledRadicalInverseSpecialized<3121>(perm, a);
        case 445:
            return ScrambledRadicalInverseSpecialized<3137>(perm, a);
        case 446:
            return ScrambledRadicalInverseSpecialized<3163>(perm, a);
        case 447:
            return ScrambledRadicalInverseSpecialized<3167>(perm, a);
        case 448:
            return ScrambledRadicalInverseSpecialized<3169>(perm, a);
        case 449:
            return ScrambledRadicalInverseSpecialized<3181>(perm, a);
        case 450:
            return ScrambledRadicalInverseSpecialized<3187>(perm, a);
        case 451:
            return ScrambledRadicalInverseSpecialized<3191>(perm, a);
        case 452:
            return ScrambledRadicalInverseSpecialized<3203>(perm, a);
        case 453:
            return ScrambledRadicalInverseSpecialized<3209>(perm, a);
        case 454:
            return ScrambledRadicalInverseSpecialized<3217>(perm, a);
        case 455:
            return ScrambledRadicalInverseSpecialized<3221>(perm, a);
        case 456:
            return ScrambledRadicalInverseSpecialized<3229>(perm, a);
        case 457:
            return ScrambledRadicalInverseSpecialized<3251>(perm, a);
        case 458:
            return ScrambledRadicalInverseSpecialized<3253>(perm, a);
        case 459:
            return ScrambledRadicalInverseSpecialized<3257>(perm, a);
        case 460:
            return ScrambledRadicalInverseSpecialized<3259>(perm, a);
        case 461:
            return ScrambledRadicalInverseSpecialized<3271>(perm, a);
        case 462:
            return ScrambledRadicalInverseSpecialized<3299>(perm, a);
        case 463:
            return ScrambledRadicalInverseSpecialized<3301>(perm, a);
        case 464:
            return ScrambledRadicalInverseSpecialized<3307>(perm, a);
        case 465:
            return ScrambledRadicalInverseSpecialized<3313>(perm, a);
        case 466:
            return ScrambledRadicalInverseSpecialized<3319>(perm, a);
        case 467:
            return ScrambledRadicalInverseSpecialized<3323>(perm, a);
        case 468:
            return ScrambledRadicalInverseSpecialized<3329>(perm, a);
        case 469:
            return ScrambledRadicalInverseSpecialized<3331>(perm, a);
        case 470:
            return ScrambledRadicalInverseSpecialized<3343>(perm, a);
        case 471:
            return ScrambledRadicalInverseSpecialized<3347>(perm, a);
        case 472:
            return ScrambledRadicalInverseSpecialized<3359>(perm, a);
        case 473:
            return ScrambledRadicalInverseSpecialized<3361>(perm, a);
        case 474:
            return ScrambledRadicalInverseSpecialized<3371>(perm, a);
        case 475:
            return ScrambledRadicalInverseSpecialized<3373>(perm, a);
        case 476:
            return ScrambledRadicalInverseSpecialized<3389>(perm, a);
        case 477:
            return ScrambledRadicalInverseSpecialized<3391>(perm, a);
        case 478:
            return ScrambledRadicalInverseSpecialized<3407>(perm, a);
        case 479:
            return ScrambledRadicalInverseSpecialized<3413>(perm, a);
        case 480:
            return ScrambledRadicalInverseSpecialized<3433>(perm, a);
        case 481:
            return ScrambledRadicalInverseSpecialized<3449>(perm, a);
        case 482:
            return ScrambledRadicalInverseSpecialized<3457>(perm, a);
        case 483:
            return ScrambledRadicalInverseSpecialized<3461>(perm, a);
        case 484:
            return ScrambledRadicalInverseSpecialized<3463>(perm, a);
        case 485:
            return ScrambledRadicalInverseSpecialized<3467>(perm, a);
        case 486:
            return ScrambledRadicalInverseSpecialized<3469>(perm, a);
        case 487:
            return ScrambledRadicalInverseSpecialized<3491>(perm, a);
        case 488:
            return ScrambledRadicalInverseSpecialized<3499>(perm, a);
        case 489:
            return ScrambledRadicalInverseSpecialized<3511>(perm, a);
        case 490:
            return ScrambledRadicalInverseSpecialized<3517>(perm, a);
        case 491:
            return ScrambledRadicalInverseSpecialized<3527>(perm, a);
        case 492:
            return ScrambledRadicalInverseSpecialized<3529>(perm, a);
        case 493:
            return ScrambledRadicalInverseSpecialized<3533>(perm, a);
        case 494:
            return ScrambledRadicalInverseSpecialized<3539>(perm, a);
        case 495:
            return ScrambledRadicalInverseSpecialized<3541>(perm, a);
        case 496:
            return ScrambledRadicalInverseSpecialized<3547>(perm, a);
        case 497:
            return ScrambledRadicalInverseSpecialized<3557>(perm, a);
        case 498:
            return ScrambledRadicalInverseSpecialized<3559>(perm, a);
        case 499:
            return ScrambledRadicalInverseSpecialized<3571>(perm, a);
        case 500:
            return ScrambledRadicalInverseSpecialized<3581>(perm, a);
        case 501:
            return ScrambledRadicalInverseSpecialized<3583>(perm, a);
        case 502:
            return ScrambledRadicalInverseSpecialized<3593>(perm, a);
        case 503:
            return ScrambledRadicalInverseSpecialized<3607>(perm, a);
        case 504:
            return ScrambledRadicalInverseSpecialized<3613>(perm, a);
        case 505:
            return ScrambledRadicalInverseSpecialized<3617>(perm, a);
        case 506:
            return ScrambledRadicalInverseSpecialized<3623>(perm, a);
        case 507:
            return ScrambledRadicalInverseSpecialized<3631>(perm, a);
        case 508:
            return ScrambledRadicalInverseSpecialized<3637>(perm, a);
        case 509:
            return ScrambledRadicalInverseSpecialized<3643>(perm, a);
        case 510:
            return ScrambledRadicalInverseSpecialized<3659>(perm, a);
        case 511:
            return ScrambledRadicalInverseSpecialized<3671>(perm, a);
        case 512:
            return ScrambledRadicalInverseSpecialized<3673>(perm, a);
        case 513:
            return ScrambledRadicalInverseSpecialized<3677>(perm, a);
        case 514:
            return ScrambledRadicalInverseSpecialized<3691>(perm, a);
        case 515:
            return ScrambledRadicalInverseSpecialized<3697>(perm, a);
        case 516:
            return ScrambledRadicalInverseSpecialized<3701>(perm, a);
        case 517:
            return ScrambledRadicalInverseSpecialized<3709>(perm, a);
        case 518:
            return ScrambledRadicalInverseSpecialized<3719>(perm, a);
        case 519:
            return ScrambledRadicalInverseSpecialized<3727>(perm, a);
        case 520:
            return ScrambledRadicalInverseSpecialized<3733>(perm, a);
        case 521:
            return ScrambledRadicalInverseSpecialized<3739>(perm, a);
        case 522:
            return ScrambledRadicalInverseSpecialized<3761>(perm, a);
        case 523:
            return ScrambledRadicalInverseSpecialized<3767>(perm, a);
        case 524:
            return ScrambledRadicalInverseSpecialized<3769>(perm, a);
        case 525:
            return ScrambledRadicalInverseSpecialized<3779>(perm, a);
        case 526:
            return ScrambledRadicalInverseSpecialized<3793>(perm, a);
        case 527:
            return ScrambledRadicalInverseSpecialized<3797>(perm, a);
        case 528:
            return ScrambledRadicalInverseSpecialized<3803>(perm, a);
        case 529:
            return ScrambledRadicalInverseSpecialized<3821>(perm, a);
        case 530:
            return ScrambledRadicalInverseSpecialized<3823>(perm, a);
        case 531:
            return ScrambledRadicalInverseSpecialized<3833>(perm, a);
        case 532:
            return ScrambledRadicalInverseSpecialized<3847>(perm, a);
        case 533:
            return ScrambledRadicalInverseSpecialized<3851>(perm, a);
        case 534:
            return ScrambledRadicalInverseSpecialized<3853>(perm, a);
        case 535:
            return ScrambledRadicalInverseSpecialized<3863>(perm, a);
        case 536:
            return ScrambledRadicalInverseSpecialized<3877>(perm, a);
        case 537:
            return ScrambledRadicalInverseSpecialized<3881>(perm, a);
        case 538:
            return ScrambledRadicalInverseSpecialized<3889>(perm, a);
        case 539:
            return ScrambledRadicalInverseSpecialized<3907>(perm, a);
        case 540:
            return ScrambledRadicalInverseSpecialized<3911>(perm, a);
        case 541:
            return ScrambledRadicalInverseSpecialized<3917>(perm, a);
        case 542:
            return ScrambledRadicalInverseSpecialized<3919>(perm, a);
        case 543:
            return ScrambledRadicalInverseSpecialized<3923>(perm, a);
        case 544:
            return ScrambledRadicalInverseSpecialized<3929>(perm, a);
        case 545:
            return ScrambledRadicalInverseSpecialized<3931>(perm, a);
        case 546:
            return ScrambledRadicalInverseSpecialized<3943>(perm, a);
        case 547:
            return ScrambledRadicalInverseSpecialized<3947>(perm, a);
        case 548:
            return ScrambledRadicalInverseSpecialized<3967>(perm, a);
        case 549:
            return ScrambledRadicalInverseSpecialized<3989>(perm, a);
        case 550:
            return ScrambledRadicalInverseSpecialized<4001>(perm, a);
        case 551:
            return ScrambledRadicalInverseSpecialized<4003>(perm, a);
        case 552:
            return ScrambledRadicalInverseSpecialized<4007>(perm, a);
        case 553:
            return ScrambledRadicalInverseSpecialized<4013>(perm, a);
        case 554:
            return ScrambledRadicalInverseSpecialized<4019>(perm, a);
        case 555:
            return ScrambledRadicalInverseSpecialized<4021>(perm, a);
        case 556:
            return ScrambledRadicalInverseSpecialized<4027>(perm, a);
        case 557:
            return ScrambledRadicalInverseSpecialized<4049>(perm, a);
        case 558:
            return ScrambledRadicalInverseSpecialized<4051>(perm, a);
        case 559:
            return ScrambledRadicalInverseSpecialized<4057>(perm, a);
        case 560:
            return ScrambledRadicalInverseSpecialized<4073>(perm, a);
        case 561:
            return ScrambledRadicalInverseSpecialized<4079>(perm, a);
        case 562:
            return ScrambledRadicalInverseSpecialized<4091>(perm, a);
        case 563:
            return ScrambledRadicalInverseSpecialized<4093>(perm, a);
        case 564:
            return ScrambledRadicalInverseSpecialized<4099>(perm, a);
        case 565:
            return ScrambledRadicalInverseSpecialized<4111>(perm, a);
        case 566:
            return ScrambledRadicalInverseSpecialized<4127>(perm, a);
        case 567:
            return ScrambledRadicalInverseSpecialized<4129>(perm, a);
        case 568:
            return ScrambledRadicalInverseSpecialized<4133>(perm, a);
        case 569:
            return ScrambledRadicalInverseSpecialized<4139>(perm, a);
        case 570:
            return ScrambledRadicalInverseSpecialized<4153>(perm, a);
        case 571:
            return ScrambledRadicalInverseSpecialized<4157>(perm, a);
        case 572:
            return ScrambledRadicalInverseSpecialized<4159>(perm, a);
        case 573:
            return ScrambledRadicalInverseSpecialized<4177>(perm, a);
        case 574:
            return ScrambledRadicalInverseSpecialized<4201>(perm, a);
        case 575:
            return ScrambledRadicalInverseSpecialized<4211>(perm, a);
        case 576:
            return ScrambledRadicalInverseSpecialized<4217>(perm, a);
        case 577:
            return ScrambledRadicalInverseSpecialized<4219>(perm, a);
        case 578:
            return ScrambledRadicalInverseSpecialized<4229>(perm, a);
        case 579:
            return ScrambledRadicalInverseSpecialized<4231>(perm, a);
        case 580:
            return ScrambledRadicalInverseSpecialized<4241>(perm, a);
        case 581:
            return ScrambledRadicalInverseSpecialized<4243>(perm, a);
        case 582:
            return ScrambledRadicalInverseSpecialized<4253>(perm, a);
        case 583:
            return ScrambledRadicalInverseSpecialized<4259>(perm, a);
        case 584:
            return ScrambledRadicalInverseSpecialized<4261>(perm, a);
        case 585:
            return ScrambledRadicalInverseSpecialized<4271>(perm, a);
        case 586:
            return ScrambledRadicalInverseSpecialized<4273>(perm, a);
        case 587:
            return ScrambledRadicalInverseSpecialized<4283>(perm, a);
        case 588:
            return ScrambledRadicalInverseSpecialized<4289>(perm, a);
        case 589:
            return ScrambledRadicalInverseSpecialized<4297>(perm, a);
        case 590:
            return ScrambledRadicalInverseSpecialized<4327>(perm, a);
        case 591:
            return ScrambledRadicalInverseSpecialized<4337>(perm, a);
        case 592:
            return ScrambledRadicalInverseSpecialized<4339>(perm, a);
        case 593:
            return ScrambledRadicalInverseSpecialized<4349>(perm, a);
        case 594:
            return ScrambledRadicalInverseSpecialized<4357>(perm, a);
        case 595:
            return ScrambledRadicalInverseSpecialized<4363>(perm, a);
        case 596:
            return ScrambledRadicalInverseSpecialized<4373>(perm, a);
        case 597:
            return ScrambledRadicalInverseSpecialized<4391>(perm, a);
        case 598:
            return ScrambledRadicalInverseSpecialized<4397>(perm, a);
        case 599:
            return ScrambledRadicalInverseSpecialized<4409>(perm, a);
        case 600:
            return ScrambledRadicalInverseSpecialized<4421>(perm, a);
        case 601:
            return ScrambledRadicalInverseSpecialized<4423>(perm, a);
        case 602:
            return ScrambledRadicalInverseSpecialized<4441>(perm, a);
        case 603:
            return ScrambledRadicalInverseSpecialized<4447>(perm, a);
        case 604:
            return ScrambledRadicalInverseSpecialized<4451>(perm, a);
        case 605:
            return ScrambledRadicalInverseSpecialized<4457>(perm, a);
        case 606:
            return ScrambledRadicalInverseSpecialized<4463>(perm, a);
        case 607:
            return ScrambledRadicalInverseSpecialized<4481>(perm, a);
        case 608:
            return ScrambledRadicalInverseSpecialized<4483>(perm, a);
        case 609:
            return ScrambledRadicalInverseSpecialized<4493>(perm, a);
        case 610:
            return ScrambledRadicalInverseSpecialized<4507>(perm, a);
        case 611:
            return ScrambledRadicalInverseSpecialized<4513>(perm, a);
        case 612:
            return ScrambledRadicalInverseSpecialized<4517>(perm, a);
        case 613:
            return ScrambledRadicalInverseSpecialized<4519>(perm, a);
        case 614:
            return ScrambledRadicalInverseSpecialized<4523>(perm, a);
        case 615:
            return ScrambledRadicalInverseSpecialized<4547>(perm, a);
        case 616:
            return ScrambledRadicalInverseSpecialized<4549>(perm, a);
        case 617:
            return ScrambledRadicalInverseSpecialized<4561>(perm, a);
        case 618:
            return ScrambledRadicalInverseSpecialized<4567>(perm, a);
        case 619:
            return ScrambledRadicalInverseSpecialized<4583>(perm, a);
        case 620:
            return ScrambledRadicalInverseSpecialized<4591>(perm, a);
        case 621:
            return ScrambledRadicalInverseSpecialized<4597>(perm, a);
        case 622:
            return ScrambledRadicalInverseSpecialized<4603>(perm, a);
        case 623:
            return ScrambledRadicalInverseSpecialized<4621>(perm, a);
        case 624:
            return ScrambledRadicalInverseSpecialized<4637>(perm, a);
        case 625:
            return ScrambledRadicalInverseSpecialized<4639>(perm, a);
        case 626:
            return ScrambledRadicalInverseSpecialized<4643>(perm, a);
        case 627:
            return ScrambledRadicalInverseSpecialized<4649>(perm, a);
        case 628:
            return ScrambledRadicalInverseSpecialized<4651>(perm, a);
        case 629:
            return ScrambledRadicalInverseSpecialized<4657>(perm, a);
        case 630:
            return ScrambledRadicalInverseSpecialized<4663>(perm, a);
        case 631:
            return ScrambledRadicalInverseSpecialized<4673>(perm, a);
        case 632:
            return ScrambledRadicalInverseSpecialized<4679>(perm, a);
        case 633:
            return ScrambledRadicalInverseSpecialized<4691>(perm, a);
        case 634:
            return ScrambledRadicalInverseSpecialized<4703>(perm, a);
        case 635:
            return ScrambledRadicalInverseSpecialized<4721>(perm, a);
        case 636:
            return ScrambledRadicalInverseSpecialized<4723>(perm, a);
        case 637:
            return ScrambledRadicalInverseSpecialized<4729>(perm, a);
        case 638:
            return ScrambledRadicalInverseSpecialized<4733>(perm, a);
        case 639:
            return ScrambledRadicalInverseSpecialized<4751>(perm, a);
        case 640:
            return ScrambledRadicalInverseSpecialized<4759>(perm, a);
        case 641:
            return ScrambledRadicalInverseSpecialized<4783>(perm, a);
        case 642:
            return ScrambledRadicalInverseSpecialized<4787>(perm, a);
        case 643:
            return ScrambledRadicalInverseSpecialized<4789>(perm, a);
        case 644:
            return ScrambledRadicalInverseSpecialized<4793>(perm, a);
        case 645:
            return ScrambledRadicalInverseSpecialized<4799>(perm, a);
        case 646:
            return ScrambledRadicalInverseSpecialized<4801>(perm, a);
        case 647:
            return ScrambledRadicalInverseSpecialized<4813>(perm, a);
        case 648:
            return ScrambledRadicalInverseSpecialized<4817>(perm, a);
        case 649:
            return ScrambledRadicalInverseSpecialized<4831>(perm, a);
        case 650:
            return ScrambledRadicalInverseSpecialized<4861>(perm, a);
        case 651:
            return ScrambledRadicalInverseSpecialized<4871>(perm, a);
        case 652:
            return ScrambledRadicalInverseSpecialized<4877>(perm, a);
        case 653:
            return ScrambledRadicalInverseSpecialized<4889>(perm, a);
        case 654:
            return ScrambledRadicalInverseSpecialized<4903>(perm, a);
        case 655:
            return ScrambledRadicalInverseSpecialized<4909>(perm, a);
        case 656:
            return ScrambledRadicalInverseSpecialized<4919>(perm, a);
        case 657:
            return ScrambledRadicalInverseSpecialized<4931>(perm, a);
        case 658:
            return ScrambledRadicalInverseSpecialized<4933>(perm, a);
        case 659:
            return ScrambledRadicalInverseSpecialized<4937>(perm, a);
        case 660:
            return ScrambledRadicalInverseSpecialized<4943>(perm, a);
        case 661:
            return ScrambledRadicalInverseSpecialized<4951>(perm, a);
        case 662:
            return ScrambledRadicalInverseSpecialized<4957>(perm, a);
        case 663:
            return ScrambledRadicalInverseSpecialized<4967>(perm, a);
        case 664:
            return ScrambledRadicalInverseSpecialized<4969>(perm, a);
        case 665:
            return ScrambledRadicalInverseSpecialized<4973>(perm, a);
        case 666:
            return ScrambledRadicalInverseSpecialized<4987>(perm, a);
        case 667:
            return ScrambledRadicalInverseSpecialized<4993>(perm, a);
        case 668:
            return ScrambledRadicalInverseSpecialized<4999>(perm, a);
        case 669:
            return ScrambledRadicalInverseSpecialized<5003>(perm, a);
        case 670:
            return ScrambledRadicalInverseSpecialized<5009>(perm, a);
        case 671:
            return ScrambledRadicalInverseSpecialized<5011>(perm, a);
        case 672:
            return ScrambledRadicalInverseSpecialized<5021>(perm, a);
        case 673:
            return ScrambledRadicalInverseSpecialized<5023>(perm, a);
        case 674:
            return ScrambledRadicalInverseSpecialized<5039>(perm, a);
        case 675:
            return ScrambledRadicalInverseSpecialized<5051>(perm, a);
        case 676:
            return ScrambledRadicalInverseSpecialized<5059>(perm, a);
        case 677:
            return ScrambledRadicalInverseSpecialized<5077>(perm, a);
        case 678:
            return ScrambledRadicalInverseSpecialized<5081>(perm, a);
        case 679:
            return ScrambledRadicalInverseSpecialized<5087>(perm, a);
        case 680:
            return ScrambledRadicalInverseSpecialized<5099>(perm, a);
        case 681:
            return ScrambledRadicalInverseSpecialized<5101>(perm, a);
        case 682:
            return ScrambledRadicalInverseSpecialized<5107>(perm, a);
        case 683:
            return ScrambledRadicalInverseSpecialized<5113>(perm, a);
        case 684:
            return ScrambledRadicalInverseSpecialized<5119>(perm, a);
        case 685:
            return ScrambledRadicalInverseSpecialized<5147>(perm, a);
        case 686:
            return ScrambledRadicalInverseSpecialized<5153>(perm, a);
        case 687:
            return ScrambledRadicalInverseSpecialized<5167>(perm, a);
        case 688:
            return ScrambledRadicalInverseSpecialized<5171>(perm, a);
        case 689:
            return ScrambledRadicalInverseSpecialized<5179>(perm, a);
        case 690:
            return ScrambledRadicalInverseSpecialized<5189>(perm, a);
        case 691:
            return ScrambledRadicalInverseSpecialized<5197>(perm, a);
        case 692:
            return ScrambledRadicalInverseSpecialized<5209>(perm, a);
        case 693:
            return ScrambledRadicalInverseSpecialized<5227>(perm, a);
        case 694:
            return ScrambledRadicalInverseSpecialized<5231>(perm, a);
        case 695:
            return ScrambledRadicalInverseSpecialized<5233>(perm, a);
        case 696:
            return ScrambledRadicalInverseSpecialized<5237>(perm, a);
        case 697:
            return ScrambledRadicalInverseSpecialized<5261>(perm, a);
        case 698:
            return ScrambledRadicalInverseSpecialized<5273>(perm, a);
        case 699:
            return ScrambledRadicalInverseSpecialized<5279>(perm, a);
        case 700:
            return ScrambledRadicalInverseSpecialized<5281>(perm, a);
        case 701:
            return ScrambledRadicalInverseSpecialized<5297>(perm, a);
        case 702:
            return ScrambledRadicalInverseSpecialized<5303>(perm, a);
        case 703:
            return ScrambledRadicalInverseSpecialized<5309>(perm, a);
        case 704:
            return ScrambledRadicalInverseSpecialized<5323>(perm, a);
        case 705:
            return ScrambledRadicalInverseSpecialized<5333>(perm, a);
        case 706:
            return ScrambledRadicalInverseSpecialized<5347>(perm, a);
        case 707:
            return ScrambledRadicalInverseSpecialized<5351>(perm, a);
        case 708:
            return ScrambledRadicalInverseSpecialized<5381>(perm, a);
        case 709:
            return ScrambledRadicalInverseSpecialized<5387>(perm, a);
        case 710:
            return ScrambledRadicalInverseSpecialized<5393>(perm, a);
        case 711:
            return ScrambledRadicalInverseSpecialized<5399>(perm, a);
        case 712:
            return ScrambledRadicalInverseSpecialized<5407>(perm, a);
        case 713:
            return ScrambledRadicalInverseSpecialized<5413>(perm, a);
        case 714:
            return ScrambledRadicalInverseSpecialized<5417>(perm, a);
        case 715:
            return ScrambledRadicalInverseSpecialized<5419>(perm, a);
        case 716:
            return ScrambledRadicalInverseSpecialized<5431>(perm, a);
        case 717:
            return ScrambledRadicalInverseSpecialized<5437>(perm, a);
        case 718:
            return ScrambledRadicalInverseSpecialized<5441>(perm, a);
        case 719:
            return ScrambledRadicalInverseSpecialized<5443>(perm, a);
        case 720:
            return ScrambledRadicalInverseSpecialized<5449>(perm, a);
        case 721:
            return ScrambledRadicalInverseSpecialized<5471>(perm, a);
        case 722:
            return ScrambledRadicalInverseSpecialized<5477>(perm, a);
        case 723:
            return ScrambledRadicalInverseSpecialized<5479>(perm, a);
        case 724:
            return ScrambledRadicalInverseSpecialized<5483>(perm, a);
        case 725:
            return ScrambledRadicalInverseSpecialized<5501>(perm, a);
        case 726:
            return ScrambledRadicalInverseSpecialized<5503>(perm, a);
        case 727:
            return ScrambledRadicalInverseSpecialized<5507>(perm, a);
        case 728:
            return ScrambledRadicalInverseSpecialized<5519>(perm, a);
        case 729:
            return ScrambledRadicalInverseSpecialized<5521>(perm, a);
        case 730:
            return ScrambledRadicalInverseSpecialized<5527>(perm, a);
        case 731:
            return ScrambledRadicalInverseSpecialized<5531>(perm, a);
        case 732:
            return ScrambledRadicalInverseSpecialized<5557>(perm, a);
        case 733:
            return ScrambledRadicalInverseSpecialized<5563>(perm, a);
        case 734:
            return ScrambledRadicalInverseSpecialized<5569>(perm, a);
        case 735:
            return ScrambledRadicalInverseSpecialized<5573>(perm, a);
        case 736:
            return ScrambledRadicalInverseSpecialized<5581>(perm, a);
        case 737:
            return ScrambledRadicalInverseSpecialized<5591>(perm, a);
        case 738:
            return ScrambledRadicalInverseSpecialized<5623>(perm, a);
        case 739:
            return ScrambledRadicalInverseSpecialized<5639>(perm, a);
        case 740:
            return ScrambledRadicalInverseSpecialized<5641>(perm, a);
        case 741:
            return ScrambledRadicalInverseSpecialized<5647>(perm, a);
        case 742:
            return ScrambledRadicalInverseSpecialized<5651>(perm, a);
        case 743:
            return ScrambledRadicalInverseSpecialized<5653>(perm, a);
        case 744:
            return ScrambledRadicalInverseSpecialized<5657>(perm, a);
        case 745:
            return ScrambledRadicalInverseSpecialized<5659>(perm, a);
        case 746:
            return ScrambledRadicalInverseSpecialized<5669>(perm, a);
        case 747:
            return ScrambledRadicalInverseSpecialized<5683>(perm, a);
        case 748:
            return ScrambledRadicalInverseSpecialized<5689>(perm, a);
        case 749:
            return ScrambledRadicalInverseSpecialized<5693>(perm, a);
        case 750:
            return ScrambledRadicalInverseSpecialized<5701>(perm, a);
        case 751:
            return ScrambledRadicalInverseSpecialized<5711>(perm, a);
        case 752:
            return ScrambledRadicalInverseSpecialized<5717>(perm, a);
        case 753:
            return ScrambledRadicalInverseSpecialized<5737>(perm, a);
        case 754:
            return ScrambledRadicalInverseSpecialized<5741>(perm, a);
        case 755:
            return ScrambledRadicalInverseSpecialized<5743>(perm, a);
        case 756:
            return ScrambledRadicalInverseSpecialized<5749>(perm, a);
        case 757:
            return ScrambledRadicalInverseSpecialized<5779>(perm, a);
        case 758:
            return ScrambledRadicalInverseSpecialized<5783>(perm, a);
        case 759:
            return ScrambledRadicalInverseSpecialized<5791>(perm, a);
        case 760:
            return ScrambledRadicalInverseSpecialized<5801>(perm, a);
        case 761:
            return ScrambledRadicalInverseSpecialized<5807>(perm, a);
        case 762:
            return ScrambledRadicalInverseSpecialized<5813>(perm, a);
        case 763:
            return ScrambledRadicalInverseSpecialized<5821>(perm, a);
        case 764:
            return ScrambledRadicalInverseSpecialized<5827>(perm, a);
        case 765:
            return ScrambledRadicalInverseSpecialized<5839>(perm, a);
        case 766:
            return ScrambledRadicalInverseSpecialized<5843>(perm, a);
        case 767:
            return ScrambledRadicalInverseSpecialized<5849>(perm, a);
        case 768:
            return ScrambledRadicalInverseSpecialized<5851>(perm, a);
        case 769:
            return ScrambledRadicalInverseSpecialized<5857>(perm, a);
        case 770:
            return ScrambledRadicalInverseSpecialized<5861>(perm, a);
        case 771:
            return ScrambledRadicalInverseSpecialized<5867>(perm, a);
        case 772:
            return ScrambledRadicalInverseSpecialized<5869>(perm, a);
        case 773:
            return ScrambledRadicalInverseSpecialized<5879>(perm, a);
        case 774:
            return ScrambledRadicalInverseSpecialized<5881>(perm, a);
        case 775:
            return ScrambledRadicalInverseSpecialized<5897>(perm, a);
        case 776:
            return ScrambledRadicalInverseSpecialized<5903>(perm, a);
        case 777:
            return ScrambledRadicalInverseSpecialized<5923>(perm, a);
        case 778:
            return ScrambledRadicalInverseSpecialized<5927>(perm, a);
        case 779:
            return ScrambledRadicalInverseSpecialized<5939>(perm, a);
        case 780:
            return ScrambledRadicalInverseSpecialized<5953>(perm, a);
        case 781:
            return ScrambledRadicalInverseSpecialized<5981>(perm, a);
        case 782:
            return ScrambledRadicalInverseSpecialized<5987>(perm, a);
        case 783:
            return ScrambledRadicalInverseSpecialized<6007>(perm, a);
        case 784:
            return ScrambledRadicalInverseSpecialized<6011>(perm, a);
        case 785:
            return ScrambledRadicalInverseSpecialized<6029>(perm, a);
        case 786:
            return ScrambledRadicalInverseSpecialized<6037>(perm, a);
        case 787:
            return ScrambledRadicalInverseSpecialized<6043>(perm, a);
        case 788:
            return ScrambledRadicalInverseSpecialized<6047>(perm, a);
        case 789:
            return ScrambledRadicalInverseSpecialized<6053>(perm, a);
        case 790:
            return ScrambledRadicalInverseSpecialized<6067>(perm, a);
        case 791:
            return ScrambledRadicalInverseSpecialized<6073>(perm, a);
        case 792:
            return ScrambledRadicalInverseSpecialized<6079>(perm, a);
        case 793:
            return ScrambledRadicalInverseSpecialized<6089>(perm, a);
        case 794:
            return ScrambledRadicalInverseSpecialized<6091>(perm, a);
        case 795:
            return ScrambledRadicalInverseSpecialized<6101>(perm, a);
        case 796:
            return ScrambledRadicalInverseSpecialized<6113>(perm, a);
        case 797:
            return ScrambledRadicalInverseSpecialized<6121>(perm, a);
        case 798:
            return ScrambledRadicalInverseSpecialized<6131>(perm, a);
        case 799:
            return ScrambledRadicalInverseSpecialized<6133>(perm, a);
        case 800:
            return ScrambledRadicalInverseSpecialized<6143>(perm, a);
        case 801:
            return ScrambledRadicalInverseSpecialized<6151>(perm, a);
        case 802:
            return ScrambledRadicalInverseSpecialized<6163>(perm, a);
        case 803:
            return ScrambledRadicalInverseSpecialized<6173>(perm, a);
        case 804:
            return ScrambledRadicalInverseSpecialized<6197>(perm, a);
        case 805:
            return ScrambledRadicalInverseSpecialized<6199>(perm, a);
        case 806:
            return ScrambledRadicalInverseSpecialized<6203>(perm, a);
        case 807:
            return ScrambledRadicalInverseSpecialized<6211>(perm, a);
        case 808:
            return ScrambledRadicalInverseSpecialized<6217>(perm, a);
        case 809:
            return ScrambledRadicalInverseSpecialized<6221>(perm, a);
        case 810:
            return ScrambledRadicalInverseSpecialized<6229>(perm, a);
        case 811:
            return ScrambledRadicalInverseSpecialized<6247>(perm, a);
        case 812:
            return ScrambledRadicalInverseSpecialized<6257>(perm, a);
        case 813:
            return ScrambledRadicalInverseSpecialized<6263>(perm, a);
        case 814:
            return ScrambledRadicalInverseSpecialized<6269>(perm, a);
        case 815:
            return ScrambledRadicalInverseSpecialized<6271>(perm, a);
        case 816:
            return ScrambledRadicalInverseSpecialized<6277>(perm, a);
        case 817:
            return ScrambledRadicalInverseSpecialized<6287>(perm, a);
        case 818:
            return ScrambledRadicalInverseSpecialized<6299>(perm, a);
        case 819:
            return ScrambledRadicalInverseSpecialized<6301>(perm, a);
        case 820:
            return ScrambledRadicalInverseSpecialized<6311>(perm, a);
        case 821:
            return ScrambledRadicalInverseSpecialized<6317>(perm, a);
        case 822:
            return ScrambledRadicalInverseSpecialized<6323>(perm, a);
        case 823:
            return ScrambledRadicalInverseSpecialized<6329>(perm, a);
        case 824:
            return ScrambledRadicalInverseSpecialized<6337>(perm, a);
        case 825:
            return ScrambledRadicalInverseSpecialized<6343>(perm, a);
        case 826:
            return ScrambledRadicalInverseSpecialized<6353>(perm, a);
        case 827:
            return ScrambledRadicalInverseSpecialized<6359>(perm, a);
        case 828:
            return ScrambledRadicalInverseSpecialized<6361>(perm, a);
        case 829:
            return ScrambledRadicalInverseSpecialized<6367>(perm, a);
        case 830:
            return ScrambledRadicalInverseSpecialized<6373>(perm, a);
        case 831:
            return ScrambledRadicalInverseSpecialized<6379>(perm, a);
        case 832:
            return ScrambledRadicalInverseSpecialized<6389>(perm, a);
        case 833:
            return ScrambledRadicalInverseSpecialized<6397>(perm, a);
        case 834:
            return ScrambledRadicalInverseSpecialized<6421>(perm, a);
        case 835:
            return ScrambledRadicalInverseSpecialized<6427>(perm, a);
        case 836:
            return ScrambledRadicalInverseSpecialized<6449>(perm, a);
        case 837:
            return ScrambledRadicalInverseSpecialized<6451>(perm, a);
        case 838:
            return ScrambledRadicalInverseSpecialized<6469>(perm, a);
        case 839:
            return ScrambledRadicalInverseSpecialized<6473>(perm, a);
        case 840:
            return ScrambledRadicalInverseSpecialized<6481>(perm, a);
        case 841:
            return ScrambledRadicalInverseSpecialized<6491>(perm, a);
        case 842:
            return ScrambledRadicalInverseSpecialized<6521>(perm, a);
        case 843:
            return ScrambledRadicalInverseSpecialized<6529>(perm, a);
        case 844:
            return ScrambledRadicalInverseSpecialized<6547>(perm, a);
        case 845:
            return ScrambledRadicalInverseSpecialized<6551>(perm, a);
        case 846:
            return ScrambledRadicalInverseSpecialized<6553>(perm, a);
        case 847:
            return ScrambledRadicalInverseSpecialized<6563>(perm, a);
        case 848:
            return ScrambledRadicalInverseSpecialized<6569>(perm, a);
        case 849:
            return ScrambledRadicalInverseSpecialized<6571>(perm, a);
        case 850:
            return ScrambledRadicalInverseSpecialized<6577>(perm, a);
        case 851:
            return ScrambledRadicalInverseSpecialized<6581>(perm, a);
        case 852:
            return ScrambledRadicalInverseSpecialized<6599>(perm, a);
        case 853:
            return ScrambledRadicalInverseSpecialized<6607>(perm, a);
        case 854:
            return ScrambledRadicalInverseSpecialized<6619>(perm, a);
        case 855:
            return ScrambledRadicalInverseSpecialized<6637>(perm, a);
        case 856:
            return ScrambledRadicalInverseSpecialized<6653>(perm, a);
        case 857:
            return ScrambledRadicalInverseSpecialized<6659>(perm, a);
        case 858:
            return ScrambledRadicalInverseSpecialized<6661>(perm, a);
        case 859:
            return ScrambledRadicalInverseSpecialized<6673>(perm, a);
        case 860:
            return ScrambledRadicalInverseSpecialized<6679>(perm, a);
        case 861:
            return ScrambledRadicalInverseSpecialized<6689>(perm, a);
        case 862:
            return ScrambledRadicalInverseSpecialized<6691>(perm, a);
        case 863:
            return ScrambledRadicalInverseSpecialized<6701>(perm, a);
        case 864:
            return ScrambledRadicalInverseSpecialized<6703>(perm, a);
        case 865:
            return ScrambledRadicalInverseSpecialized<6709>(perm, a);
        case 866:
            return ScrambledRadicalInverseSpecialized<6719>(perm, a);
        case 867:
            return ScrambledRadicalInverseSpecialized<6733>(perm, a);
        case 868:
            return ScrambledRadicalInverseSpecialized<6737>(perm, a);
        case 869:
            return ScrambledRadicalInverseSpecialized<6761>(perm, a);
        case 870:
            return ScrambledRadicalInverseSpecialized<6763>(perm, a);
        case 871:
            return ScrambledRadicalInverseSpecialized<6779>(perm, a);
        case 872:
            return ScrambledRadicalInverseSpecialized<6781>(perm, a);
        case 873:
            return ScrambledRadicalInverseSpecialized<6791>(perm, a);
        case 874:
            return ScrambledRadicalInverseSpecialized<6793>(perm, a);
        case 875:
            return ScrambledRadicalInverseSpecialized<6803>(perm, a);
        case 876:
            return ScrambledRadicalInverseSpecialized<6823>(perm, a);
        case 877:
            return ScrambledRadicalInverseSpecialized<6827>(perm, a);
        case 878:
            return ScrambledRadicalInverseSpecialized<6829>(perm, a);
        case 879:
            return ScrambledRadicalInverseSpecialized<6833>(perm, a);
        case 880:
            return ScrambledRadicalInverseSpecialized<6841>(perm, a);
        case 881:
            return ScrambledRadicalInverseSpecialized<6857>(perm, a);
        case 882:
            return ScrambledRadicalInverseSpecialized<6863>(perm, a);
        case 883:
            return ScrambledRadicalInverseSpecialized<6869>(perm, a);
        case 884:
            return ScrambledRadicalInverseSpecialized<6871>(perm, a);
        case 885:
            return ScrambledRadicalInverseSpecialized<6883>(perm, a);
        case 886:
            return ScrambledRadicalInverseSpecialized<6899>(perm, a);
        case 887:
            return ScrambledRadicalInverseSpecialized<6907>(perm, a);
        case 888:
            return ScrambledRadicalInverseSpecialized<6911>(perm, a);
        case 889:
            return ScrambledRadicalInverseSpecialized<6917>(perm, a);
        case 890:
            return ScrambledRadicalInverseSpecialized<6947>(perm, a);
        case 891:
            return ScrambledRadicalInverseSpecialized<6949>(perm, a);
        case 892:
            return ScrambledRadicalInverseSpecialized<6959>(perm, a);
        case 893:
            return ScrambledRadicalInverseSpecialized<6961>(perm, a);
        case 894:
            return ScrambledRadicalInverseSpecialized<6967>(perm, a);
        case 895:
            return ScrambledRadicalInverseSpecialized<6971>(perm, a);
        case 896:
            return ScrambledRadicalInverseSpecialized<6977>(perm, a);
        case 897:
            return ScrambledRadicalInverseSpecialized<6983>(perm, a);
        case 898:
            return ScrambledRadicalInverseSpecialized<6991>(perm, a);
        case 899:
            return ScrambledRadicalInverseSpecialized<6997>(perm, a);
        case 900:
            return ScrambledRadicalInverseSpecialized<7001>(perm, a);
        case 901:
            return ScrambledRadicalInverseSpecialized<7013>(perm, a);
        case 902:
            return ScrambledRadicalInverseSpecialized<7019>(perm, a);
        case 903:
            return ScrambledRadicalInverseSpecialized<7027>(perm, a);
        case 904:
            return ScrambledRadicalInverseSpecialized<7039>(perm, a);
        case 905:
            return ScrambledRadicalInverseSpecialized<7043>(perm, a);
        case 906:
            return ScrambledRadicalInverseSpecialized<7057>(perm, a);
        case 907:
            return ScrambledRadicalInverseSpecialized<7069>(perm, a);
        case 908:
            return ScrambledRadicalInverseSpecialized<7079>(perm, a);
        case 909:
            return ScrambledRadicalInverseSpecialized<7103>(perm, a);
        case 910:
            return ScrambledRadicalInverseSpecialized<7109>(perm, a);
        case 911:
            return ScrambledRadicalInverseSpecialized<7121>(perm, a);
        case 912:
            return ScrambledRadicalInverseSpecialized<7127>(perm, a);
        case 913:
            return ScrambledRadicalInverseSpecialized<7129>(perm, a);
        case 914:
            return ScrambledRadicalInverseSpecialized<7151>(perm, a);
        case 915:
            return ScrambledRadicalInverseSpecialized<7159>(perm, a);
        case 916:
            return ScrambledRadicalInverseSpecialized<7177>(perm, a);
        case 917:
            return ScrambledRadicalInverseSpecialized<7187>(perm, a);
        case 918:
            return ScrambledRadicalInverseSpecialized<7193>(perm, a);
        case 919:
            return ScrambledRadicalInverseSpecialized<7207>(perm, a);
        case 920:
            return ScrambledRadicalInverseSpecialized<7211>(perm, a);
        case 921:
            return ScrambledRadicalInverseSpecialized<7213>(perm, a);
        case 922:
            return ScrambledRadicalInverseSpecialized<7219>(perm, a);
        case 923:
            return ScrambledRadicalInverseSpecialized<7229>(perm, a);
        case 924:
            return ScrambledRadicalInverseSpecialized<7237>(perm, a);
        case 925:
            return ScrambledRadicalInverseSpecialized<7243>(perm, a);
        case 926:
            return ScrambledRadicalInverseSpecialized<7247>(perm, a);
        case 927:
            return ScrambledRadicalInverseSpecialized<7253>(perm, a);
        case 928:
            return ScrambledRadicalInverseSpecialized<7283>(perm, a);
        case 929:
            return ScrambledRadicalInverseSpecialized<7297>(perm, a);
        case 930:
            return ScrambledRadicalInverseSpecialized<7307>(perm, a);
        case 931:
            return ScrambledRadicalInverseSpecialized<7309>(perm, a);
        case 932:
            return ScrambledRadicalInverseSpecialized<7321>(perm, a);
        case 933:
            return ScrambledRadicalInverseSpecialized<7331>(perm, a);
        case 934:
            return ScrambledRadicalInverseSpecialized<7333>(perm, a);
        case 935:
            return ScrambledRadicalInverseSpecialized<7349>(perm, a);
        case 936:
            return ScrambledRadicalInverseSpecialized<7351>(perm, a);
        case 937:
            return ScrambledRadicalInverseSpecialized<7369>(perm, a);
        case 938:
            return ScrambledRadicalInverseSpecialized<7393>(perm, a);
        case 939:
            return ScrambledRadicalInverseSpecialized<7411>(perm, a);
        case 940:
            return ScrambledRadicalInverseSpecialized<7417>(perm, a);
        case 941:
            return ScrambledRadicalInverseSpecialized<7433>(perm, a);
        case 942:
            return ScrambledRadicalInverseSpecialized<7451>(perm, a);
        case 943:
            return ScrambledRadicalInverseSpecialized<7457>(perm, a);
        case 944:
            return ScrambledRadicalInverseSpecialized<7459>(perm, a);
        case 945:
            return ScrambledRadicalInverseSpecialized<7477>(perm, a);
        case 946:
            return ScrambledRadicalInverseSpecialized<7481>(perm, a);
        case 947:
            return ScrambledRadicalInverseSpecialized<7487>(perm, a);
        case 948:
            return ScrambledRadicalInverseSpecialized<7489>(perm, a);
        case 949:
            return ScrambledRadicalInverseSpecialized<7499>(perm, a);
        case 950:
            return ScrambledRadicalInverseSpecialized<7507>(perm, a);
        case 951:
            return ScrambledRadicalInverseSpecialized<7517>(perm, a);
        case 952:
            return ScrambledRadicalInverseSpecialized<7523>(perm, a);
        case 953:
            return ScrambledRadicalInverseSpecialized<7529>(perm, a);
        case 954:
            return ScrambledRadicalInverseSpecialized<7537>(perm, a);
        case 955:
            return ScrambledRadicalInverseSpecialized<7541>(perm, a);
        case 956:
            return ScrambledRadicalInverseSpecialized<7547>(perm, a);
        case 957:
            return ScrambledRadicalInverseSpecialized<7549>(perm, a);
        case 958:
            return ScrambledRadicalInverseSpecialized<7559>(perm, a);
        case 959:
            return ScrambledRadicalInverseSpecialized<7561>(perm, a);
        case 960:
            return ScrambledRadicalInverseSpecialized<7573>(perm, a);
        case 961:
            return ScrambledRadicalInverseSpecialized<7577>(perm, a);
        case 962:
            return ScrambledRadicalInverseSpecialized<7583>(perm, a);
        case 963:
            return ScrambledRadicalInverseSpecialized<7589>(perm, a);
        case 964:
            return ScrambledRadicalInverseSpecialized<7591>(perm, a);
        case 965:
            return ScrambledRadicalInverseSpecialized<7603>(perm, a);
        case 966:
            return ScrambledRadicalInverseSpecialized<7607>(perm, a);
        case 967:
            return ScrambledRadicalInverseSpecialized<7621>(perm, a);
        case 968:
            return ScrambledRadicalInverseSpecialized<7639>(perm, a);
        case 969:
            return ScrambledRadicalInverseSpecialized<7643>(perm, a);
        case 970:
            return ScrambledRadicalInverseSpecialized<7649>(perm, a);
        case 971:
            return ScrambledRadicalInverseSpecialized<7669>(perm, a);
        case 972:
            return ScrambledRadicalInverseSpecialized<7673>(perm, a);
        case 973:
            return ScrambledRadicalInverseSpecialized<7681>(perm, a);
        case 974:
            return ScrambledRadicalInverseSpecialized<7687>(perm, a);
        case 975:
            return ScrambledRadicalInverseSpecialized<7691>(perm, a);
        case 976:
            return ScrambledRadicalInverseSpecialized<7699>(perm, a);
        case 977:
            return ScrambledRadicalInverseSpecialized<7703>(perm, a);
        case 978:
            return ScrambledRadicalInverseSpecialized<7717>(perm, a);
        case 979:
            return ScrambledRadicalInverseSpecialized<7723>(perm, a);
        case 980:
            return ScrambledRadicalInverseSpecialized<7727>(perm, a);
        case 981:
            return ScrambledRadicalInverseSpecialized<7741>(perm, a);
        case 982:
            return ScrambledRadicalInverseSpecialized<7753>(perm, a);
        case 983:
            return ScrambledRadicalInverseSpecialized<7757>(perm, a);
        case 984:
            return ScrambledRadicalInverseSpecialized<7759>(perm, a);
        case 985:
            return ScrambledRadicalInverseSpecialized<7789>(perm, a);
        case 986:
            return ScrambledRadicalInverseSpecialized<7793>(perm, a);
        case 987:
            return ScrambledRadicalInverseSpecialized<7817>(perm, a);
        case 988:
            return ScrambledRadicalInverseSpecialized<7823>(perm, a);
        case 989:
            return ScrambledRadicalInverseSpecialized<7829>(perm, a);
        case 990:
            return ScrambledRadicalInverseSpecialized<7841>(perm, a);
        case 991:
            return ScrambledRadicalInverseSpecialized<7853>(perm, a);
        case 992:
            return ScrambledRadicalInverseSpecialized<7867>(perm, a);
        case 993:
            return ScrambledRadicalInverseSpecialized<7873>(perm, a);
        case 994:
            return ScrambledRadicalInverseSpecialized<7877>(perm, a);
        case 995:
            return ScrambledRadicalInverseSpecialized<7879>(perm, a);
        case 996:
            return ScrambledRadicalInverseSpecialized<7883>(perm, a);
        case 997:
            return ScrambledRadicalInverseSpecialized<7901>(perm, a);
        case 998:
            return ScrambledRadicalInverseSpecialized<7907>(perm, a);
        case 999:
            return ScrambledRadicalInverseSpecialized<7919>(perm, a);
        case 1000:
            return ScrambledRadicalInverseSpecialized<7927>(perm, a);
        case 1001:
            return ScrambledRadicalInverseSpecialized<7933>(perm, a);
        case 1002:
            return ScrambledRadicalInverseSpecialized<7937>(perm, a);
        case 1003:
            return ScrambledRadicalInverseSpecialized<7949>(perm, a);
        case 1004:
            return ScrambledRadicalInverseSpecialized<7951>(perm, a);
        case 1005:
            return ScrambledRadicalInverseSpecialized<7963>(perm, a);
        case 1006:
            return ScrambledRadicalInverseSpecialized<7993>(perm, a);
        case 1007:
            return ScrambledRadicalInverseSpecialized<8009>(perm, a);
        case 1008:
            return ScrambledRadicalInverseSpecialized<8011>(perm, a);
        case 1009:
            return ScrambledRadicalInverseSpecialized<8017>(perm, a);
        case 1010:
            return ScrambledRadicalInverseSpecialized<8039>(perm, a);
        case 1011:
            return ScrambledRadicalInverseSpecialized<8053>(perm, a);
        case 1012:
            return ScrambledRadicalInverseSpecialized<8059>(perm, a);
        case 1013:
            return ScrambledRadicalInverseSpecialized<8069>(perm, a);
        case 1014:
            return ScrambledRadicalInverseSpecialized<8081>(perm, a);
        case 1015:
            return ScrambledRadicalInverseSpecialized<8087>(perm, a);
        case 1016:
            return ScrambledRadicalInverseSpecialized<8089>(perm, a);
        case 1017:
            return ScrambledRadicalInverseSpecialized<8093>(perm, a);
        case 1018:
            return ScrambledRadicalInverseSpecialized<8101>(perm, a);
        case 1019:
            return ScrambledRadicalInverseSpecialized<8111>(perm, a);
        case 1020:
            return ScrambledRadicalInverseSpecialized<8117>(perm, a);
        case 1021:
            return ScrambledRadicalInverseSpecialized<8123>(perm, a);
        case 1022:
            return ScrambledRadicalInverseSpecialized<8147>(perm, a);
        case 1023:
            return ScrambledRadicalInverseSpecialized<8161>(perm, a);
        default:
            std::cout << "Base" << baseIndex << " is >= 1024, the limit of ScrambledRadicalInverse";
            return 0;
    }
}