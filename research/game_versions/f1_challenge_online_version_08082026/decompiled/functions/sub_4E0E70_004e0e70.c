int __thiscall sub_4E0E70(char *this, int a2)
{
  int *v2; // edi
  int result; // eax

  v2 = (int *)&this[296 * a2];
  sub_4E0D70(v2 + 81);
  sub_4E2230(a2, 0.0);
  v2 += 98;
  result = sub_4E0D70(v2);
  if ( *v2 )
    return sub_54C030(0, 0, 0, 0);
  return result;
}
