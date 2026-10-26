void __stdcall sub_41B220(float *a1)
{
  int v1; // eax

  if ( dword_7688A0
    && flt_7678BC != 0.0
    && byte_6292D8
    && sub_4633A0(&unk_764D70) != 1
    && (unsigned __int8)sub_4EED40(a1) )
  {
    switch ( (unsigned int)(__int64)(flt_7D74DC * 2.236936292054402 + 0.5) )
    {
      case 0x1Eu:
        v1 = 1;
        goto LABEL_16;
      case 0x23u:
        v1 = 2;
        goto LABEL_16;
      case 0x28u:
        v1 = 4;
        goto LABEL_16;
      case 0x2Du:
        v1 = 8;
        goto LABEL_16;
      case 0x32u:
        v1 = 16;
        goto LABEL_16;
      case 0x37u:
        v1 = 32;
        goto LABEL_16;
      case 0x3Cu:
        v1 = 64;
        goto LABEL_16;
      case 0x41u:
        v1 = 128;
        goto LABEL_16;
      case 0x46u:
        v1 = 256;
LABEL_16:
        sub_4195A0(v1);
        break;
      default:
        break;
    }
    if ( flt_7D74DC + 2.2349999 < sqrt(a1[4407] * a1[4407] + a1[4408] * a1[4408] + a1[4409] * a1[4409]) )
      sub_4195D0(16, 1);
  }
}
