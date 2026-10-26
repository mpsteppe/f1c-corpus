void __thiscall sub_4F9670(int this, char a2, int a3)
{
  int v4; // ebx
  int i; // edi
  unsigned int v6; // ecx
  int v7; // edx
  _DWORD *v8; // ecx
  _DWORD *v9; // edi
  signed int j; // edi
  signed int k; // edi
  bool v12; // bl
  bool v13; // al

  v4 = *(_DWORD *)(this + 280);
  for ( i = 0; i < 48; ++i )
  {
    if ( v4 > 1 )
      v6 = sub_4F83E0((_DWORD *)(this + 356), i);
    else
      v6 = *(unsigned __int8 *)(i + this + 304);
    if ( v6 < 0x30 )
    {
      v7 = dword_630030[6326 * v6];
      if ( v7 != -1 && (v7 != 2 || fabs(*((float *)&unk_632230 + 6326 * v6) - dbl_7DA9D0) < 3.0) )
        break;
    }
  }
  if ( v6 < 0x30 )
  {
    v8 = (_DWORD *)((char *)&unk_6310CC + 25304 * v6);
    v9 = v8;
    switch ( v4 )
    {
      case 0:
        if ( a2 )
        {
          sub_4F7ED0((_DWORD *)(this + 356));
          sub_4F9920(1, a3);
          *(_DWORD *)(this + 284) = 5;
        }
        break;
      case 1:
        if ( sub_4DEB10(v8) )
        {
          if ( sub_4F95D0(this) )
          {
            sub_45D100(&byte_764D68, (int)aFullCaution, 3, 16909060, 0);
          }
          else
          {
            *(_DWORD *)(this + 284) = 4;
            sub_45D100(&byte_764D68, (int)aQuickieCaution, 3, 16909060, 0);
          }
          if ( *(_BYTE *)(this + 163) )
            *(_DWORD *)(this + 284) = 2;
          if ( sub_460A50() )
            goto LABEL_21;
          sub_4F9920(2, -1);
        }
        break;
      case 2:
        if ( (unsigned __int8)sub_4FA660(0) )
        {
          if ( *(int *)(this + 284) >= 5 )
            sub_4F9920(3, -1);
          else
            sub_4F9920(4, -1);
          for ( j = 0; j < (int)NumOfElements; ++j )
            sub_427540(dword_75AAD0[j]);
        }
        break;
      case 3:
        if ( (unsigned __int8)sub_4FA660(1) )
        {
          sub_4F9920(4, -1);
          for ( k = 0; k < (int)NumOfElements; ++k )
            sub_427540(dword_75AAD0[k]);
        }
        break;
      case 4:
      case 5:
        if ( dword_766228 >= *(_DWORD *)(this + 284) - 1 )
        {
          if ( sub_460A50() )
LABEL_21:
            sub_4F9920(8, -1);
          else
            sub_4F9920(6, -1);
        }
        break;
      case 6:
        sub_4BBF10();
        sub_41BBF0(flt_629328);
        if ( (unsigned __int8)sub_4FA1A0(this) )
          sub_4F9920(7, -1);
        break;
      case 7:
        v12 = (unsigned __int8)sub_4BBF20() == 0;
        v13 = !sub_4DEB10(v9);
        if ( v12 && v13 )
          sub_4F9920(0, -1);
        break;
      default:
        break;
    }
  }
  if ( *(int *)(this + 280) >= 2 && sub_463490(dword_764D70) )
    sub_4FAE10(this);
}
