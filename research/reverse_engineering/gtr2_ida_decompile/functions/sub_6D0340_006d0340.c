int __stdcall sub_6D0340(_DWORD *a1, int a2)
{
  _DWORD *v3; // esi
  int result; // eax
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // edi
  _WORD *v9; // eax
  _DWORD *v10; // ebx
  int v11; // eax
  unsigned __int8 *v12; // [esp+8h] [ebp-1Ch] BYREF
  int v13; // [esp+Ch] [ebp-18h]
  int v14; // [esp+10h] [ebp-14h]
  int v15; // [esp+14h] [ebp-10h]
  _DWORD *v16; // [esp+18h] [ebp-Ch]
  int v17; // [esp+1Ch] [ebp-8h]
  _WORD *v18; // [esp+20h] [ebp-4h]
  int v19; // [esp+2Ch] [ebp+8h]

  v3 = (_DWORD *)a1[112];
  v17 = 1 << a1[104];
  if ( !a1[70] || v3[10] || (result = sub_6CFE70()) != 0 )
  {
    v5 = a1[6];
    v16 = a1;
    v12 = *(unsigned __int8 **)v5;
    v13 = *(_DWORD *)(v5 + 4);
    v6 = v3[4];
    v7 = 0;
    v8 = v3[3];
    v19 = 0;
    if ( (int)a1[90] <= 0 )
    {
LABEL_11:
      v10 = (_DWORD *)a1[6];
      *v10 = v12;
      v10[1] = v13;
      v11 = v3[10];
      v3[3] = v8;
      v3[10] = v11 - 1;
      v3[4] = v6;
      return 1;
    }
    while ( 1 )
    {
      v9 = *(_WORD **)(a2 + 4 * v7);
      v18 = v9;
      if ( v6 < 1 )
      {
        if ( !sub_6CF670(&v12, v8, v6, 1) )
          return 0;
        v8 = v14;
        v6 = v15;
        v9 = v18;
      }
      if ( ((v8 >> --v6) & 1) != 0 )
        *v9 |= v17;
      v7 = ++v19;
      if ( v19 >= a1[90] )
        goto LABEL_11;
    }
  }
  return result;
}
