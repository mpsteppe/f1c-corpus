BOOL sub_4D19A0()
{
  int v0; // esi
  BOOL result; // eax

  v0 = sub_42F2D0(&unk_62BF64);
  for ( result = sub_42F2C0(&unk_62BF64); !result; result = sub_42F2C0(&unk_62BF64) )
  {
    sub_4EEA00((char *)&unk_62BF68 + 25304 * v0);
    v0 = sub_42F310(&unk_62BF64);
  }
  return result;
}
