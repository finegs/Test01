void __attribute__ ((constructor))so_init(void);
void __attribute__ ((destructor))so_uninit(void);

// executed before dlopen()
void so_init(void)
{
	// do nothing,...
}

// executed before dlclose()
void so_uninit(void)
{
	// do nothing,...
}
