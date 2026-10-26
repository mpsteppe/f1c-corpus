_DWORD *__thiscall sub_40E170(int this)
{
  int v2; // eax
  int v3; // edi
  int v4; // ecx

  v2 = *(_DWORD *)(this + 136);
  if ( v2 && *(_DWORD *)(v2 + 36) == 10 )
    EngineGuardedInitializer(this + 20);
  v3 = *(_DWORD *)(this + 8);
  v4 = *(_DWORD *)(v3 + 2804);
  if ( v4 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(v4);
  BufferInitWith10fDefaults(v3);
  return CameraDirectorResetInit((char *)this);
}

