#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class web_interface_node : public rclcpp::Node {
public:
    web_interface_node() : Node("web_interface_node") {
        
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "mode_command", 10, [this](const std_msgs::msg::String::SharedPtr msg) {
                callback(msg);
            });
        
        RCLCPP_INFO(this->get_logger(), "web_interface_node READY");
    }

private:
    void callback(const std_msgs::msg::String::SharedPtr msg) {
        auto mode = msg->data;
        RCLCPP_INFO(this->get_logger(), "message received");
        // Ajoutez le code pour changer le comportement de la voiture en fonction du mode reçu
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<web_interface_node>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}