// f1c  0x0059801a  size=97
int __cdecl sub_59801A(int a1, int a2)
{
  char *v2; // edx
  char v3; // cl
  char v4; // cl
  int v5; // eax

  v2 = (char *)(dword_8D4920[a1 >> 5] + 36 * (a1 & 0x1F) + 4);
  v3 = *v2;
  if ( a2 == 0x8000 )
  {
    v4 = v3 & 0x7F;
LABEL_5:
    v5 = -(*v2 < 0);
    *v2 = v4;
    LOWORD(v5) = v5 & 0xC000;
    return v5 + 0x8000;
  }
  if ( a2 == 0x4000 )
  {
    v4 = v3 | 0x80;
    goto LABEL_5;
  }
  *(_DWORD *)sub_58AFCF() = 22;
  return -1;
}
