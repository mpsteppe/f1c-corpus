int __userpurge sub_528A30@<eax>(int *a1@<ecx>, int a2@<edi>, int a3, int a4)
{
  int v6; // ecx

  sub_527EB0((int)a1, 0, a2, 1, 0);
  if ( (_BYTE)a4 )
  {
    sub_526340();
    sub_526220();
    return off_16C92B4(a3, a4);
  }
  else
  {
    (*(void (__thiscall **)(int *, int, _DWORD))(a1[445] + 16))(a1 + 445, a3, 0);
    if ( sub_5268F0((int)a1, a1 + 445) )
    {
      sub_522980(a1, a1[723211]);
      v6 = a1[446];
      a1[468] = 2;
      return v6 != 0;
    }
    else
    {
      (*(void (__thiscall **)(int *))(a1[445] + 20))(a1 + 445);
      return a1[446] != 0;
    }
  }
}
