int __thiscall sub_552CA0(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *v4; // esi
  int result; // eax
  int v6; // eax
  int v7; // [esp+0h] [ebp-10h]
  float retaddr; // [esp+10h] [ebp+0h]

  if ( (dword_B640C4 & 1) != 0 || !sub_53F260(a2) )
  {
    result = sub_54F270(this, (int)a2);
    if ( !(_BYTE)result )
    {
      if ( *(_BYTE *)this && (v6 = sub_5511F0(&unk_FADD40, 0), v6 >= 0) && a2[4821] < dword_924FF4[5654 * v6] - 1 )
      {
        this[2 * this[209] + 1] = a2[5617];
        *(float *)&this[2 * this[209]++ + 2] = retaddr;
      }
      else
      {
        this[2 * this[418] + 210] = a2[5617];
        *(float *)&this[2 * this[418]++ + 211] = retaddr;
      }
      result = (_BYTE)dword_757C1C != 0 ? dword_91E084 : 0;
      if ( a2 == (_DWORD *)result && (dword_B640C4 & 1) != 0 )
      {
        sub_54F1F0(this, (int)a2);
        return sub_52C150();
      }
    }
  }
  else
  {
    v4 = (_DWORD *)off_9034A4;
    if ( dword_82F4A0 < 1023 )
    {
      ++dword_82F4A0;
      off_9034A4 += 848;
    }
    *(float *)&v7 = dbl_FB1D18;
    result = sub_51B2A0(v4, 4, 39, 4, a2[5617], v7, 3);
    v4[2] = a2[4888];
  }
  return result;
}
