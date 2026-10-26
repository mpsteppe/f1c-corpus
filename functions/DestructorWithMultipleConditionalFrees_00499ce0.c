LPVOID __thiscall sub_499CE0(LPVOID *this)
{
  LPVOID result; // eax
  void *v3; // esi

  *this = &off_5ACAAC;
  TreeNodeRecursiveDestructor(0);
  LinkedListFree(this + 27);
  if ( this[22] )
    FreeWrapper_7bcf(this[22]);
  if ( this[20] )
    FreeWrapper_7bcf(this[20]);
  if ( this[18] )
    FreeWrapper_7bcf(this[18]);
  if ( this[16] )
    FreeWrapper_7bcf(this[16]);
  if ( this[14] )
    FreeWrapper_7bcf(this[14]);
  if ( this[12] )
    FreeWrapper_7bcf(this[12]);
  if ( this[10] )
    FreeWrapper_7bcf(this[10]);
  if ( this[8] )
    FreeWrapper_7bcf(this[8]);
  result = this[6];
  if ( result )
    result = (LPVOID)FreeWrapper_7bcf(this[6]);
  v3 = this[4];
  if ( v3 )
    return (LPVOID)FreeWrapper_7bcf(v3);
  return result;
}
