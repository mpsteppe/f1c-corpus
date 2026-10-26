// positive sp value has been detected, the output may be wrong!
void *__cdecl sub_4F328B(size_t a1)
{
  int v1; // ecx

  if ( !--dword_1739965 )
    dword_1739965 = 383;
  if ( *(_DWORD *)(v1 + 8) )
    return *(void **)(v1 + 8);
  else
    return operator new(a1);
}
