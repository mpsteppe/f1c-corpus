int __thiscall sub_430250(_DWORD *this, unsigned int a2)
{
  int result; // eax
  char *v4; // eax
  int i; // esi
  int v6; // edi
  int j; // eax
  int k; // esi
  float v9[3]; // [esp+2Ch] [ebp-30h] BYREF
  float v10[3]; // [esp+38h] [ebp-24h] BYREF
  float v11; // [esp+60h] [ebp+4h]

  result = a2;
  if ( this[29] != a2 )
  {
    this[29] = a2;
    if ( a2 > 2 )
      result = sub_555670(off_16C9A00);
    if ( dword_B640C0 == 5 )
    {
      result = this[29];
      switch ( result )
      {
        case 0:
        case 2:
        case 4:
          goto LABEL_23;
        case 3:
          if ( byte_B6FFF4 )
          {
            if ( (unsigned __int8)sub_4735A0(&dword_B6CBA8) && byte_B73540 )
              v4 = sub_41D840(&byte_91CC38, "Prepare for Race Start...");
            else
              v4 = sub_41D840(&byte_91CC38, "Begin Formation Lap");
            sub_4730C0(v4, 3, &byte_1020304, 1084227584);
          }
          if ( byte_B71D20 == 1 )
            sub_562AC0(&dword_FAE988, 1);
          for ( i = 0; i < dword_757C10; ++i )
            sub_429540();
          v6 = this[30];
          if ( v6 == 1 || v6 == 2 )
          {
            if ( (dword_B640C4 & 1) != 0 )
            {
              sub_52B4B0(0);
              sub_429540();
            }
            sub_54FD90(off_757C18);
            sub_4035C0();
            v11 = sub_403040(&flt_91BCA0, v9);
            if ( sub_403040(&flt_91BCA0, v10) > v11 )
            {
              for ( j = 0; j < dword_757C10; ++j )
                *(_DWORD *)(*(&dword_91E088 + j) + 19552) = -1;
            }
          }
LABEL_23:
          result = dword_757C10;
          for ( k = 0; k < dword_757C10; ++k )
          {
            sub_53E550(*(&dword_91E088 + k), 0, 1);
            result = dword_757C10;
          }
          break;
        case 5:
          if ( (unsigned __int8)sub_53F260(dword_91E084) && sub_42FE50(this) )
            sub_52C870(0, 1);
          result = sub_52B230(&byte_9034D0, 1);
          if ( this[2] == 6 )
          {
            for ( result = 0; result < dword_757C10; ++result )
              *(_DWORD *)(*(&dword_91E088 + result) + 20424) = 2;
          }
          break;
        default:
          return result;
      }
    }
  }
  return result;
}
