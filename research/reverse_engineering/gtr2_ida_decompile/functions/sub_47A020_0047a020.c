int __usercall sub_47A020@<eax>(int result@<eax>, float a2@<ecx>)
{
  int *v2; // edx
  _DWORD *v3; // ebp
  int v4; // edi
  int v5; // esi
  bool v6; // al
  int v7; // edi
  bool v8; // bl
  __int16 v9; // fps
  bool v10; // c0
  char v11; // c2
  bool v12; // c3
  __int16 v13; // fps
  bool v14; // c0
  char v15; // c2
  bool v16; // c3
  int v17; // [esp-4h] [ebp-2Ch]
  int v18; // [esp+0h] [ebp-28h]
  float v19; // [esp+Ch] [ebp-1Ch]
  float v20; // [esp+10h] [ebp-18h]
  int v21; // [esp+1Ch] [ebp-Ch] BYREF
  int *v22; // [esp+20h] [ebp-8h] BYREF
  float v23; // [esp+24h] [ebp-4h] BYREF

  v2 = (int *)(LODWORD(a2) + 112888);
  v3 = &unk_9204A0;
  while ( 1 )
  {
    if ( v3[3705] == 2 )
    {
      result = *(_DWORD *)(LODWORD(a2) + 113328);
      if ( result == 2 || result == 1 )
        v4 = *(v2 - 27798);
      else
        v4 = *v2;
      if ( v4 != -1 )
      {
        v5 = LODWORD(a2) + 292692;
        v6 = sub_479900((__int16 *)(LODWORD(a2) + 292692), v4, &v23);
        v21 = v4;
        v7 = *(_DWORD *)v5;
        v8 = v6;
        sub_4796F0((_DWORD *)(*(_DWORD *)v5 + 113304), &v22, &v21);
        HIWORD(result) = HIWORD(v22);
        if ( v22 == *(int **)(v7 + 113308) )
        {
          v20 = 0.0;
        }
        else
        {
          result = *((unsigned __int8 *)v22 + 16);
          v20 = *(float *)(v5 + 4 * result + 28);
        }
        v10 = v20 < (double)flt_B735A0;
        v11 = 0;
        v12 = v20 == flt_B735A0;
        LOWORD(result) = v9;
        if ( v20 > (double)flt_B735A0 || v8 )
        {
          result = sub_53F0E0(0);
          v14 = v19 < 1.0;
          v15 = 0;
          v16 = v19 == 1.0;
          LOWORD(result) = v13;
          if ( v19 > 1.0 )
            result = sub_53F190(v3, 0, v17, v18);
        }
      }
    }
    v2 = (int *)(LODWORD(v19) + 4);
    v3 += 5654;
    LODWORD(v19) += 4;
    if ( (int)v3 >= (int)dword_B5E860 )
      break;
    a2 = v20;
  }
  return result;
}
