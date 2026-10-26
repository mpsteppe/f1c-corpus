// attributes: thunk
int __thiscall VTableInitConditionalResourceFree(_DWORD *this)
{
  return DestructorWithResourceCleanup(this);
}
