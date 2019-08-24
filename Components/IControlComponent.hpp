class IControlComponent {
    public:
        virtual ~IControlComponent() {}
        virtual void update() = 0;
};
