int __cdecl sub_5AEDA2(_DWORD *a1)
{
  int result; // eax

  result = sub_5AECBC();
  if ( (result & 0x20) != 0 && (result & 0x80u) != 0 )
  {
    *a1 = sub_5BA67B;
    a1[1] = sub_5B98A4;
    a1[2] = sub_5BA942;
    a1[3] = sub_5B5A59;
    a1[5] = sub_5BA6D2;
    a1[6] = sub_5B9917;
    a1[7] = sub_5B9980;
    a1[8] = sub_5BA9C6;
    a1[9] = sub_5BA70D;
    a1[10] = sub_5B9E64;
    a1[11] = sub_5B5C8B;
    a1[13] = sub_5BAD70;
    a1[14] = sub_5BADB3;
    a1[15] = sub_5B9E6F;
    a1[16] = sub_5B9FFB;
    a1[17] = sub_5BAA25;
    a1[18] = sub_5BA773;
    a1[19] = sub_5B9886;
    a1[20] = sub_5B457C;
    a1[21] = sub_5B4615;
    a1[22] = sub_5BAF55;
    a1[23] = sub_5BAE97;
    a1[24] = sub_5B4672;
    a1[25] = sub_5B46B6;
    a1[26] = &sub_5B4AE7;
    a1[27] = sub_5B5D5A;
    a1[28] = sub_5B5DAA;
    a1[29] = sub_5B5E95;
    a1[30] = sub_5B4BAC;
    a1[31] = sub_5B5F71;
    a1[32] = sub_5B5FD6;
    a1[33] = sub_5B6036;
    a1[34] = sub_5B6091;
    a1[35] = sub_5BAFB9;
    a1[36] = sub_5B4C18;
    a1[37] = sub_5B4D4F;
    a1[38] = sub_5B60D8;
    a1[39] = sub_5B6147;
    a1[40] = sub_5B62CE;
    a1[41] = &sub_5B74CA;
    a1[42] = sub_5B766F;
    a1[43] = sub_5B7BA3;
    a1[44] = sub_5B4DDC;
    a1[45] = sub_5B4E6E;
    a1[55] = sub_5BAB59;
    a1[52] = sub_5B99DF;
    a1[49] = sub_5BA80B;
    a1[47] = sub_5BA854;
    a1[53] = sub_5BABCA;
    a1[50] = sub_5B9A50;
    a1[56] = sub_5B4ED2;
    a1[57] = sub_5B4F79;
    a1[54] = sub_5BAC92;
    a1[48] = sub_5BA897;
    a1[51] = sub_5B9B24;
    a1[4] = sub_5B9158;
    a1[46] = sub_5B501E;
    a1[59] = sub_5BA3C0;
    a1[58] = sub_5BA500;
    if ( (result & 0x100) != 0 && (result & 0x200) != 0 )
    {
      a1[16] = sub_5BA218;
      a1[19] = sub_5B8E76;
      a1[39] = sub_5B6219;
      a1[40] = sub_5B7CBE;
      a1[25] = sub_5B48D2;
    }
  }
  if ( (result & 0x40) != 0 )
  {
    a1[63] = sub_5B3F40;
    a1[64] = &off_5B3FE0;
    a1[65] = &off_5B4300;
    a1[60] = &off_5B38C0;
    a1[61] = &off_5B3B20;
    a1[62] = &off_5B3D80;
    a1[66] = sub_5B3800;
    a1[69] = sub_5B3740;
  }
  return result;
}
