int __thiscall sub_4A73B0(int this, int a2)
{
  int result; // eax
  int v4; // ecx
  int *v5; // eax
  int v6; // ebx
  int v7; // ebp
  int v8; // edx
  char *v9; // eax
  int v10; // [esp+4h] [ebp-18h]
  int v11; // [esp+8h] [ebp-14h]
  int v12; // [esp+Ch] [ebp-10h] BYREF
  int v13; // [esp+10h] [ebp-Ch] BYREF
  float v14; // [esp+14h] [ebp-8h]
  float v15; // [esp+18h] [ebp-4h]

  sub_4AE870(&v13, &v12);
  result = *(_DWORD *)(a2 + 12);
  v4 = 0;
  v11 = 0;
  if ( result > 0 )
  {
    while ( 1 )
    {
      if ( v4 < 0 || v4 >= result )
        goto LABEL_10;
      v5 = *(int **)a2;
      if ( v4 > 0 )
        break;
LABEL_9:
      if ( !v5 )
        goto LABEL_10;
      v6 = *v5;
LABEL_12:
      v7 = *(_DWORD *)(this + 312);
      v10 = *(_DWORD *)(this + 332);
      if ( *(_DWORD *)(v6 + 44) )
      {
        if ( !(unsigned __int8)sub_4A7560(v6, v13, v12) )
          goto LABEL_17;
        v7 = *(_DWORD *)(this + 320);
        v8 = *(_DWORD *)(this + 340);
      }
      else
      {
        v7 = *(_DWORD *)(this + 316);
        v8 = *(_DWORD *)(this + 336);
      }
      v10 = v8;
LABEL_17:
      v15 = (double)dword_6152E8 * 0.00125 * *(float *)(this + 328);
      v14 = (double)dword_6152EC * 0.0016666667 * *(float *)(this + 328);
      sub_506B20(v7);
      sub_506960(0);
      v9 = *(char **)v6;
      if ( !*(_DWORD *)v6 )
        v9 = &byte_629120;
      sub_5070D0(v9, 0.5, 1.1, v10, 5, v15, v14, 0, 0);
      result = *(_DWORD *)(a2 + 12);
      if ( ++v11 >= result )
        return result;
      v4 = v11;
    }
    while ( v5 )
    {
      v5 = (int *)v5[1];
      if ( --v4 <= 0 )
        goto LABEL_9;
    }
LABEL_10:
    v6 = 0;
    goto LABEL_12;
  }
  return result;
}
