int __stdcall sub_678BA0(int *a1)
{
  int v2; // eax
  int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // eax

  while ( a1[105] || (*(_DWORD *)(a1[111] + 12) ? sub_6789F0(a1) : sub_678B00(a1)) )
  {
    v2 = a1[105];
    switch ( v2 )
    {
      case 1:
      case 208:
      case 209:
      case 210:
      case 211:
      case 212:
      case 213:
      case 214:
      case 215:
        v8 = *a1;
        *(_DWORD *)(v8 + 20) = 92;
        *(_DWORD *)(v8 + 24) = v2;
        (*(void (__stdcall **)(int *, int))(v8 + 4))(a1, 1);
        a1[105] = 0;
        continue;
      case 192:
      case 193:
        v4 = 0;
        v5 = 0;
        goto LABEL_14;
      case 194:
        v4 = 0;
        goto LABEL_13;
      case 195:
      case 197:
      case 198:
      case 199:
      case 200:
      case 203:
      case 205:
      case 206:
      case 207:
        v7 = *a1;
        *(_DWORD *)(v7 + 20) = 60;
        *(_DWORD *)(v7 + 24) = v2;
        (*(void (__stdcall **)(int *))v7)(a1);
        a1[105] = 0;
        continue;
      case 196:
        if ( !sub_677F70(a1) )
          return 0;
        a1[105] = 0;
        continue;
      case 201:
        if ( !sub_6779D0(1, 0, a1) )
          return 0;
        goto LABEL_32;
      case 202:
        v4 = 1;
LABEL_13:
        v5 = 1;
LABEL_14:
        v3 = sub_6779D0(v4, v5, a1);
        goto LABEL_15;
      case 204:
      case 220:
        if ( !sub_678940(a1) )
          return 0;
        a1[105] = 0;
        continue;
      case 216:
        v3 = sub_677920(a1);
LABEL_15:
        if ( !v3 )
          return 0;
        a1[105] = 0;
        break;
      case 217:
        v10 = *a1;
        *(_DWORD *)(v10 + 20) = 85;
        (*(void (__stdcall **)(int *, int))(v10 + 4))(a1, 1);
        a1[105] = 0;
        return 2;
      case 218:
        if ( !sub_677CB0(a1) )
          return 0;
        a1[105] = 0;
        return 1;
      case 219:
        if ( !sub_678240(a1) )
          return 0;
        a1[105] = 0;
        continue;
      case 221:
        if ( !sub_678490(a1) )
          return 0;
        a1[105] = 0;
        continue;
      case 224:
      case 225:
      case 226:
      case 227:
      case 228:
      case 229:
      case 230:
      case 231:
      case 232:
      case 233:
      case 234:
      case 235:
      case 236:
      case 237:
      case 238:
      case 239:
        if ( !(*(int (__stdcall **)(int *))(a1[111] + 4 * v2 - 864))(a1) )
          return 0;
        a1[105] = 0;
        continue;
      case 254:
        if ( !(*(int (__stdcall **)(int *))(a1[111] + 28))(a1) )
          return 0;
        a1[105] = 0;
        continue;
      default:
        v9 = *a1;
        *(_DWORD *)(v9 + 20) = 68;
        *(_DWORD *)(v9 + 24) = v2;
        (*(void (__stdcall **)(int *))v9)(a1);
LABEL_32:
        a1[105] = 0;
        continue;
    }
  }
  return 0;
}
