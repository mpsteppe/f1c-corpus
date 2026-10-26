unsigned __int16 *__thiscall sub_5EB210(_DWORD *this, int a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  unsigned __int16 *result; // eax
  int v6; // esi
  int v7; // ecx
  _DWORD *v8; // esi
  _DWORD *v9; // esi
  _DWORD *v10; // edx
  int v11; // ecx
  _DWORD *v12; // esi
  _DWORD *v13; // esi
  _DWORD *v14; // eax

  result = (unsigned __int16 *)a2;
  if ( a2 >= 0 && a2 < this[92] )
  {
    result = (unsigned __int16 *)(this[93] + 36 * a2);
    v6 = *((_DWORD *)result + 2);
    v7 = *result;
    if ( (*(_BYTE *)v6 & 8) != 0 )
    {
      if ( a3 )
      {
        v8 = (_DWORD *)(88 * v7 + *(_DWORD *)(v6 + 32));
        *a3 = *v8;
        a3[1] = v8[1];
        a3[2] = v8[2];
      }
      if ( a4 )
      {
        v9 = (_DWORD *)(88 * result[1] + *(_DWORD *)(*((_DWORD *)result + 2) + 32));
        *a4 = *v9;
        a4[1] = v9[1];
        a4[2] = v9[2];
      }
      v10 = a5;
      if ( a5 )
      {
        v11 = 88 * result[2];
LABEL_16:
        v14 = (_DWORD *)(v11 + *(_DWORD *)(*((_DWORD *)result + 2) + 32));
        *v10 = *v14;
        v10[1] = v14[1];
        result = (unsigned __int16 *)v14[2];
        v10[2] = result;
      }
    }
    else
    {
      if ( a3 )
      {
        v12 = (_DWORD *)((v7 << 6) + *(_DWORD *)(v6 + 32));
        *a3 = *v12;
        a3[1] = v12[1];
        a3[2] = v12[2];
      }
      if ( a4 )
      {
        v13 = (_DWORD *)((result[1] << 6) + *(_DWORD *)(*((_DWORD *)result + 2) + 32));
        *a4 = *v13;
        a4[1] = v13[1];
        a4[2] = v13[2];
      }
      v10 = a5;
      if ( a5 )
      {
        v11 = result[2] << 6;
        goto LABEL_16;
      }
    }
  }
  return result;
}
