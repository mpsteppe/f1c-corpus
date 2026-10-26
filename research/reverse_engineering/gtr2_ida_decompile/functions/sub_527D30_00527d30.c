char __usercall sub_527D30@<al>(_DWORD *a1@<ecx>, int a2@<edi>)
{
  int *v2; // esi
  char result; // al

  if ( *a1 == 2 )
  {
    v2 = a1 + 1;
    sub_5239A0(a1 + 1);
    return sub_527AF0(v2, a2);
  }
  return result;
}
