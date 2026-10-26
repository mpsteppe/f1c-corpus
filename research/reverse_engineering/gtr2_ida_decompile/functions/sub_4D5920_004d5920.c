int __thiscall sub_4D5920(int this, int a2)
{
  int result; // eax
  int v4; // ecx
  int *v5; // eax
  int v6; // ebx
  int v7; // ebp
  int v8; // edx
  const CHAR *v9; // eax
  float v10; // [esp+0h] [ebp-1Ch]
  int v11; // [esp+4h] [ebp-18h]
  int v12; // [esp+4h] [ebp-18h]
  int v13; // [esp+Ch] [ebp-10h] BYREF
  int v14; // [esp+10h] [ebp-Ch] BYREF
  float v15; // [esp+14h] [ebp-8h]
  float v16; // [esp+18h] [ebp-4h]
  _DWORD *retaddr; // [esp+1Ch] [ebp+0h]

  sub_4DE540(&v14, &v13);
  result = *(_DWORD *)(a2 + 12);
  v4 = 0;
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
      v11 = *(_DWORD *)(this + 332);
      if ( *(_DWORD *)(v6 + 44) )
      {
        if ( !sub_4D3810(v6, v14, v13) )
          goto LABEL_17;
        v7 = *(_DWORD *)(this + 320);
        v8 = *(_DWORD *)(this + 340);
      }
      else
      {
        v7 = *(_DWORD *)(this + 316);
        v8 = *(_DWORD *)(this + 336);
      }
      v11 = v8;
LABEL_17:
      v16 = (double)*(int *)dword_903EB8 * 0.00125 * *(float *)(this + 328);
      v15 = (double)dword_903EBC * 0.0016666667 * *(float *)(this + 328);
      sub_567E70(v7);
      sub_568750(v6 + 48, 0);
      v9 = *(const CHAR **)v6;
      if ( !*(_DWORD *)v6 )
        v9 = WindowName;
      sub_568D20((int)v9, 0.5, 1.1, v10, 5, v15, *(float *)&v14, 0, 0);
      result = retaddr[3];
      v12 = v11 + 1;
      if ( v12 >= result )
        return result;
      v4 = v12;
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
