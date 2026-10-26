char __thiscall sub_41DD20(int this, int a2)
{
  int *v3; // eax
  int v4; // edi
  int v5; // eax
  int *v6; // eax
  int *v7; // eax
  int v8; // edi
  int v9; // eax
  int *v10; // eax

  (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "Credits=%d\n", *(float *)(this + 60));
  (*(void (__cdecl **)(int, const char *))(*(_DWORD *)a2 + 32))(a2, word_6F2E64);
  v3 = *(int **)(this + 20);
  *(_DWORD *)(this + 28) = v3;
  if ( v3 )
  {
    v4 = *v3;
    if ( *v3 )
    {
      do
      {
        (*(void (__cdecl **)(int, const char *))(*(_DWORD *)a2 + 32))(a2, "[CHALLENGE]\n");
        (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "Challenge=\"%s\"\n", v4);
        (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "Result=%d\n", *(_DWORD *)(v4 + 64));
        (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "BestTime=%f\n", *(float *)(v4 + 68));
        (*(void (__cdecl **)(int, const char *))(*(_DWORD *)a2 + 32))(a2, word_6F2E64);
        v5 = *(_DWORD *)(this + 28);
        if ( !v5 )
          break;
        v6 = *(int **)(v5 + 4);
        *(_DWORD *)(this + 28) = v6;
        if ( !v6 )
          break;
        v4 = *v6;
      }
      while ( *v6 );
    }
  }
  v7 = *(int **)(this + 36);
  *(_DWORD *)(this + 44) = v7;
  if ( v7 )
  {
    v8 = *v7;
    if ( *v7 )
    {
      do
      {
        (*(void (__cdecl **)(int, const char *))(*(_DWORD *)a2 + 32))(a2, "[CHAMPIONSHIP]\n");
        (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "Championship=\"%s\"\n", v8);
        (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "Result=%d\n", *(_DWORD *)(v8 + 64));
        (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "BestPos=%d\n", *(_DWORD *)(v8 + 68));
        (*(void (**)(int, const char *, ...))(*(_DWORD *)a2 + 32))(a2, "BestPoints=%f\n", *(float *)(v8 + 72));
        (*(void (__cdecl **)(int, const char *))(*(_DWORD *)a2 + 32))(a2, word_6F2E64);
        v9 = *(_DWORD *)(this + 44);
        if ( !v9 )
          break;
        v10 = *(int **)(v9 + 4);
        *(_DWORD *)(this + 44) = v10;
        if ( !v10 )
          break;
        v8 = *v10;
      }
      while ( *v10 );
    }
  }
  return 1;
}
