char __usercall sub_527AF0@<al>(int *a1@<ecx>, int a2@<edi>)
{
  int v3; // eax
  int v4; // ecx
  int *v5; // ecx
  int v6; // eax
  int v7; // ecx

  v3 = *a1;
  v4 = *(_DWORD *)(*a1 + 2892948);
  if ( v4 )
  {
    *(_DWORD *)(v3 + 2892948) = v4 - 1;
    v5 = (int *)*a1;
    if ( *(_DWORD *)(*a1 + 2892948) )
    {
      sub_522980(v5, v5[723238]);
      v6 = *a1;
      v7 = *(_DWORD *)(*a1 + 2892956);
    }
    else
    {
      sub_522980(v5, v5[723238]);
      v6 = *a1;
      v7 = *(_DWORD *)(*a1 + 2892952);
    }
    *(_DWORD *)(v6 + 2892856) = v7;
  }
  if ( *(float *)(*a1 + 2892852) == *(float *)(*a1 + 2892856) && !*(_BYTE *)(*a1 + 2892960) )
    return 0;
  sub_522DB0();
  sub_527470(*a1, *(float *)(*a1 + 2892852));
  if ( !*(_DWORD *)(*a1 + 2892916) )
    sub_523870(a1, a2, *(float *)(*a1 + 2892852));
  *(_BYTE *)(*a1 + 2892960) = 0;
  return 1;
}
