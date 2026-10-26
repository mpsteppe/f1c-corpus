void __thiscall sub_615A50(int this, const char *a2)
{
  signed int v3; // esi
  char *v4; // ebx
  unsigned int v5; // eax
  char *v6; // edi

  if ( a2 )
  {
    if ( *(_DWORD *)this )
    {
      v3 = strlen(a2) + strlen(*(const char **)this);
      if ( *(_DWORD *)(this + 4) < v3 )
      {
        v4 = (char *)operator new(v3 + 1);
        strcpy(v4, *(const char **)this);
        j__free(*(void **)this);
        *(_DWORD *)this = v4;
        *(_DWORD *)(this + 4) = v3;
      }
      v5 = strlen(a2) + 1;
      v6 = (char *)(*(_DWORD *)this - 1);
      while ( *++v6 )
        ;
      qmemcpy(v6, a2, v5);
    }
    else
    {
      sub_615860(this, a2);
    }
  }
}
