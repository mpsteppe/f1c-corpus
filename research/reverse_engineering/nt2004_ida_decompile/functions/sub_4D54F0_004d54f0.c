int __thiscall sub_4D54F0(int **this, int a2)
{
  int **v2; // ebp
  int *v3; // eax
  bool v4; // zf
  int v5; // esi
  int *v6; // eax
  int v7; // esi
  int v8; // eax
  int *v9; // eax
  int result; // eax
  int v11; // [esp-8h] [ebp-1Ch]
  int v13; // [esp+10h] [ebp-4h]

  v2 = this + 17;
  v13 = 49;
  do
  {
    v3 = *v2;
    v4 = *v2 == 0;
    v2[1] = *v2;
    if ( v4 )
      v5 = 0;
    else
      v5 = *v3;
    if ( (unsigned __int8)sub_4EED40(a2) )
      this[510] = *(int **)(a2 + 25248);
    if ( v5 )
    {
      if ( sub_4D47D0((const char *)v5, a2) )
        goto LABEL_27;
      if ( *(float *)(v5 + 136) == -1.0e32 )
        *(float *)(v5 + 136) = dbl_7DA9D0;
    }
    if ( *(_DWORD *)(a2 + 16584) != -1 )
    {
      v6 = this[4];
      v7 = 0;
      this[6] = v6;
      if ( v6 )
      {
        v7 = *v6;
        v11 = *v6;
        *((_BYTE *)v6 + 8) = 0;
        if ( !(unsigned __int8)sub_4DAE20(v11, 1) )
          v7 = 0;
      }
      if ( !v7 )
      {
        if ( operator new(4u) )
          v8 = sub_4DB040(0);
        else
          v8 = 0;
        sub_4DB7D0(v8, 0);
        v7 = sub_4DB980(this + 4);
      }
      sub_4D4890(v7, a2);
      *(float *)(v7 + 132) = dbl_7DA9D0;
      v9 = (int *)operator new(0xCu);
      if ( v9 )
      {
        *v9 = v7;
        v9[1] = 0;
        *((_BYTE *)v9 + 8) = 0;
      }
      else
      {
        v9 = 0;
      }
      if ( *(v2 - 1) )
      {
        (*v2)[1] = (int)v9;
      }
      else
      {
        *(v2 - 1) = v9;
        v2[1] = v9;
      }
      *v2 = v9;
      v2[2] = (int *)((char *)v2[2] + 1);
    }
LABEL_27:
    v2 += 4;
    result = v13 - 1;
    v4 = v13 == 1;
    a2 += 25304;
    --v13;
  }
  while ( !v4 );
  return result;
}
