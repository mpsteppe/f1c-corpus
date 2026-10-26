int __stdcall sub_4EC440(int a1)
{
  int v1; // ebx
  int v2; // esi
  int v3; // edi
  int v4; // eax

  v1 = *(_DWORD *)dword_B640C8;
  v2 = a1;
  v3 = 1;
  if ( a1 == -1 )
  {
    switch ( *(_DWORD *)dword_B640C8 )
    {
      case 1:
        v2 = 2;
        goto LABEL_14;
      case 2:
        v2 = 3;
        goto LABEL_14;
      case 3:
        v2 = 4;
        goto LABEL_14;
      case 4:
        v2 = 5;
        goto LABEL_14;
      case 5:
        v2 = 6;
        goto LABEL_14;
      case 6:
        v2 = 6;
        if ( (unsigned __int8)sub_4735E0(&dword_B6CBA8) )
          sub_42FE80((int)&dword_B640C0);
        goto LABEL_14;
      default:
        return v3;
    }
  }
  if ( *(_DWORD *)dword_B640C8 == 6 && (unsigned __int8)sub_4735E0(&dword_B6CBA8) )
    sub_42FE80((int)&dword_B640C0);
  if ( a1 != 7 )
  {
LABEL_14:
    sub_537D80(&unk_B76270);
    sub_430F70(&dword_B640C0, v2);
    if ( (unsigned __int8)sub_4735E0(&dword_B6CBA8) && byte_B6CBC3 )
      CINet::NextSession((CINet *)dword_B6CBB0, v2);
    if ( *(_DWORD *)dword_B72314 == 4 )
    {
      v4 = sub_532D20(&unk_B76270);
      if ( v4 )
      {
        if ( !byte_FADD28 )
        {
          if ( v1 == 6 )
          {
            sub_4EC220();
            return 0;
          }
          sub_5373C0(v4);
        }
      }
    }
    return 0;
  }
  return v3;
}
