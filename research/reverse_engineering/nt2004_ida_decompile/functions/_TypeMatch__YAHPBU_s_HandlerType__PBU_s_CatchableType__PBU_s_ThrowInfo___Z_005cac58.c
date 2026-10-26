BOOL __cdecl TypeMatch(
        const struct _s_HandlerType *a1,
        const struct _s_CatchableType *a2,
        const struct _s_ThrowInfo *a3)
{
  TypeDescriptor *pType; // eax
  TypeDescriptor *v4; // ecx
  BOOL result; // eax

  pType = a1->pType;
  result = 1;
  if ( pType && pType->name[0] )
  {
    v4 = a2->pType;
    if ( pType != v4 )
    {
      if ( strcmp(pType->name, v4->name) )
        return 0;
    }
    if ( (a2->properties & 2) != 0 && (a1->adjectives & 8) == 0
      || (a3->attributes & 1) != 0 && (a1->adjectives & 1) == 0
      || (a3->attributes & 2) != 0 && (a1->adjectives & 2) == 0 )
    {
      return 0;
    }
  }
  return result;
}
