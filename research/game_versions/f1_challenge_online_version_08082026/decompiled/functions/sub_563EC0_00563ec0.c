int __fastcall sub_563EC0(_DWORD *a1, int a2, int a3, int a4)
{
  int (*v4)(); // eax

  switch ( a4 )
  {
    case 0:
      v4 = sub_563F20;
      break;
    case 1:
      v4 = (int (*)())sub_563F70;
      break;
    case 2:
      v4 = (int (*)())sub_564000;
      break;
    default:
      v4 = sub_564090;
      break;
  }
  a1[32] = a3;
  a1[33] = a2;
  dword_8D46B4 = (int)a1;
  return sub_564A00(a1[1], v4);
}
