// f1c  0x004b5c50  size=330
int __thiscall sub_4B5C50(int **this, int a2)
{
  int **v2; // ebp
  int *v3; // eax
  bool v4; // zf
  int v5; // esi
  int *v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax
  int result; // eax
  int v11; // [esp-8h] [ebp-1Ch]
  int v13; // [esp+10h] [ebp-4h]

  v2 = this + 17;
  v13 = 104;
  do
  {
    v3 = *v2;
    v4 = *v2 == 0;
    v2[1] = *v2;
    if ( !v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        if ( sub_4B5120((const char *)v5, a2) )
          goto LABEL_23;
        if ( *(float *)(v5 + 136) == -1.0e32 )
          *(float *)(v5 + 136) = dbl_8AFEA0;
      }
    }
    if ( *(_DWORD *)(a2 + 13000) != -1 )
    {
      v6 = this[4];
      v7 = 0;
      this[6] = v6;
      if ( v6 )
      {
        v7 = *v6;
        v11 = *v6;
        *((_BYTE *)v6 + 8) = 0;
        if ( !(unsigned __int8)sub_4BA830(v11, 1) )
          v7 = 0;
      }
      if ( !v7 )
      {
        if ( sub_587C03(4) )
          v8 = sub_4BAA50(0);
        else
          v8 = 0;
        sub_4BAF10(v8, 0);
        v7 = sub_4BB0C0(this + 4);
      }
      sub_4B51E0((char *)v7, a2);
      *(float *)(v7 + 132) = dbl_8AFEA0;
      v9 = sub_587C03(12);
      if ( v9 )
      {
        *(_DWORD *)v9 = v7;
        *(_DWORD *)(v9 + 4) = 0;
        *(_BYTE *)(v9 + 8) = 0;
      }
      else
      {
        v9 = 0;
      }
      if ( *(v2 - 1) )
      {
        (*v2)[1] = v9;
      }
      else
      {
        *(v2 - 1) = (int *)v9;
        v2[1] = (int *)v9;
      }
      *v2 = (int *)v9;
      v2[2] = (int *)((char *)v2[2] + 1);
    }
LABEL_23:
    v2 += 4;
    result = v13 - 1;
    v4 = v13 == 1;
    a2 += 18624;
    --v13;
  }
  while ( !v4 );
  return result;
}
