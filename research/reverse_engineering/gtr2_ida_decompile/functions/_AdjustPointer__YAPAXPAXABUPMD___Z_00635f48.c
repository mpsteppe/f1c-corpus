char *__usercall AdjustPointer@<eax>(int a1@<eax>, _DWORD *a2@<ecx>)
{
  char *result; // eax

  result = (char *)(a1 + *a2);
  if ( (int)a2[1] >= 0 )
    result += a2[1] + *(_DWORD *)(*(_DWORD *)(a2[1] + a1) + a2[2]);
  return result;
}
