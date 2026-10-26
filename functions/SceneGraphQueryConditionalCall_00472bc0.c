int __thiscall SceneGraphQueryConditionalCall(void *this)
{
  _DWORD *v2; // eax

  WindowControlTypeDetection();
  v2 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 19);
  if ( v2 )
    ObjectNameComparison(v2, (int)this);
  return 0;
}
