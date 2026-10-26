_DWORD *__thiscall SessionConfigReader(_DWORD *this, int a2)
{
  _DWORD *v3; // eax
  char *v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // ebx
  char *v7; // eax
  int v8; // esi
  _DWORD *v9; // eax
  unsigned __int8 *v10; // eax
  _DWORD *v11; // eax
  unsigned __int8 *v12; // eax
  _DWORD *v13; // eax
  unsigned __int8 *v14; // eax
  _DWORD *v15; // eax
  unsigned __int8 *v16; // eax
  _DWORD *result; // eax

  if ( !AudioChannelStop(dword_8AD3B4, aSceneorder) )
    return 0;
  v3 = (_DWORD *)NullCheckWrapper(a2);
  if ( !v3 )
    return 0;
  v4 = StringPointerAccessor(v3);
  v5 = (_DWORD *)SeasonRacesSectionFinder((int)v4);
  v6 = v5;
  if ( !v5 )
    return 0;
  v7 = StringPointerAccessor(v5);
  TrackSceneLoader(v7);
  v8 = dword_8AC490 + 396 * dword_8AC48C;
  StringCopyWithBufferRealloc((int)(this + 11336), (const char *)(v8 + 260));
  StringCopyWithBufferRealloc((int)(this + 11338), (const char *)(v8 + 4));
  v9 = StringKeyedLinkedListSearch(v6, (int)aQualifylaps);
  if ( v9 )
  {
    v10 = (unsigned __int8 *)DataEntryAccessor(v9);
    this[11340] = sub_587ECE(v10);
  }
  else
  {
    this[11340] = -1;
  }
  v11 = StringKeyedLinkedListSearch(v6, (int)aQualifytime);
  if ( v11 )
  {
    v12 = (unsigned __int8 *)DataEntryAccessor(v11);
    this[11341] = sub_587ECE(v12);
  }
  else
  {
    this[11341] = -1;
  }
  v13 = StringKeyedLinkedListSearch(v6, (int)aRacelaps);
  if ( v13 )
  {
    v14 = (unsigned __int8 *)DataEntryAccessor(v13);
    this[11342] = sub_587ECE(v14);
  }
  else
  {
    this[11342] = -1;
  }
  v15 = StringKeyedLinkedListSearch(v6, (int)aRacetime);
  if ( v15 )
  {
    v16 = (unsigned __int8 *)DataEntryAccessor(v15);
    this[11343] = sub_587ECE(v16);
  }
  else
  {
    this[11343] = -1;
  }
  if ( a2 >= this[11346] )
  {
    result = this + 11336;
    this[11344] = -1;
  }
  else
  {
    this[11344] = this[a2 + 11233];
    return this + 11336;
  }
  return result;
}

