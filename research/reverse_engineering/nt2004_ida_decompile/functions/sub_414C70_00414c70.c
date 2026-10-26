int __thiscall sub_414C70(int this, char *String2)
{
  int v2; // ebx
  int v4; // edi
  char *v5; // eax
  int result; // eax

  v2 = 0;
  if ( !String2 )
    return v2;
  if ( !_strcmpi(aPlayer_2, String2) )
  {
    v4 = sub_40C460(*(void **)(this + 4));
    sub_40C3F0(*(_DWORD ***)(this + 4));
    v2 = sub_40C460(*(void **)(this + 4));
    if ( v4 )
    {
      v5 = (char *)sub_459B80(v4);
      sub_40C400(*(int ****)(this + 4), v5);
    }
    return v2;
  }
  if ( !_strcmpi(aOriginal, String2) )
    return *(_DWORD *)(this + 120);
  if ( !_strcmpi(aLast, String2) )
    return *(_DWORD *)(this + 124);
  if ( !_strcmpi(aAnyTrackside, String2) )
    return v2;
  result = _strcmpi(aNone_1, String2);
  if ( result )
    return sub_40C480(*(int ****)(this + 4), String2);
  return result;
}
